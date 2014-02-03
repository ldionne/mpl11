/*!
 * @file
 * Contains unit tests for the @ref Monoid typeclass.
 */

#include <boost/mpl11/monoid.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

///////////////////////////
// Test method dispatching
///////////////////////////
struct Archetype1 { template <typename> using from = quote<id>; };
struct archetype1 { struct type { using mpl_datatype = Archetype1; }; };

struct Archetype2;
struct archetype2 { struct type { using mpl_datatype = Archetype2; }; };

struct plus_tag;
struct zero_tag;

namespace boost { namespace mpl11 {
    template <>
    struct common_datatype<Archetype1, Archetype2> {
        using type = Archetype1;
    };

    template <>
    struct Monoid<Archetype1> {
        template <typename, typename>
        struct plus_impl { using type = plus_tag; };

        template <typename ...>
        struct zero_impl { using type = zero_tag; };
    };
}} // end namespace boost::mpl11

static_assert(std_is_same<
    plus<archetype1, archetype1>::type,
    plus_tag
>::value, "");

static_assert(std_is_same<
    plus<archetype1, archetype2>::type,
    plus_tag
>::value, "");

static_assert(std_is_same<
    plus<archetype2, archetype1>::type,
    plus_tag
>::value, "");


static_assert(std_is_same<
    zero<Archetype1>::type,
    zero_tag
>::value, "");


int main() { }
