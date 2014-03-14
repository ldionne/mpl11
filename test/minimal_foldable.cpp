/*!
 * @file
 * Contains unit tests for `minimal_foldable`.
 */

#include "minimal_foldable.hpp"

#include <boost/mpl11/detail/dependent.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/integer.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

template <typename x, typename y>
struct f { using type = f<typename x::type, typename y::type>; };

struct s { using type = s; };
struct w { using type = w; };
struct x { using type = x; };
struct y { using type = y; };
struct z { using type = z; };


static_assert(std_is_same<
    foldl<undefined, s, minimal_foldable<>>::type, s
>::value, "");

static_assert(std_is_same<
    foldr<undefined, s, minimal_foldable<>>::type, s
>::value, "");


template <typename ...xs>
struct folding {
    using structure = minimal_foldable<xs...>;
    using Foldr = typename foldr<quote<f>, s, structure>::type;
    using Foldl = typename foldl<quote<f>, s, structure>::type;
    using Foldr1 = typename foldr1<quote<f>, structure>::type;
    using Foldl1 = typename foldl1<quote<f>, structure>::type;

    template <typename expected, typename = Foldr>
    struct right_is : detail::dependent<expected>::template type<folding> {
        static_assert(std_is_same<Foldr, expected>::value, "");
    };

    template <typename expected, typename = Foldl>
    struct left_is : detail::dependent<expected>::template type<folding> {
        static_assert(std_is_same<Foldl, expected>::value, "");
    };

    template <typename expected, typename = Foldr1>
    struct right1_is : detail::dependent<expected>::template type<folding> {
        static_assert(std_is_same<Foldr1, expected>::value, "");
    };

    template <typename expected, typename = Foldl1>
    struct left1_is : detail::dependent<expected>::template type<folding> {
        static_assert(std_is_same<Foldl1, expected>::value, "");
    };
};

struct tests
    : folding<w>
        ::right_is<f<w, s>>
        ::right1_is<w>

        ::left_is<f<s, w>>
        ::left1_is<w>

    , folding<w, x>
        ::right_is<f<w, f<x, s>>>
        ::right1_is<f<w, x>>

        ::left_is<f<f<s, w>, x>>
        ::left1_is<f<w, x>>

    , folding<w, x, y>
        ::right_is<f<w, f<x, f<y, s>>>>
        ::right1_is<f<w, f<x, y>>>

        ::left_is<f<f<f<s, w>, x>, y>>
        ::left1_is<f<f<w, x>, y>>

    , folding<w, x, y, z>
        ::right_is<f<w, f<x, f<y, f<z, s>>>>>
        ::right1_is<f<w, f<x, f<y, z>>>>

        ::left_is<f<f<f<f<s, w>, x>, y>, z>>
        ::left1_is<f<f<f<w, x>, y>, z>>
{ };


int main() { }
