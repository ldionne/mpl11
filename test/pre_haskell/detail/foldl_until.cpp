/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::foldl_until`.
 */

#include <boost/mpl11/detail/foldl_until.hpp>

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/head.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>

#include "../minimal_requirements.hpp"


using namespace boost::mpl11;
using detail::foldl_until;
using detail::is_same;

template <int> struct x;

template <int ...i>
using sequence = test::wrapper<
    test::minimal_requirements<Sequence>, vector<x<i>...>
>;

template <int ...i>
struct gather {
    template <typename Predicate>
    struct until_pred {
        template <typename Gathered, typename ToFold>
        struct Accumulator
            : push_back<Gathered, head_t<ToFold>>
        { };

        using Gathered = typename foldl_until<
            Predicate,
            sequence<i...>,
            vector<>,
            quote<Accumulator>
        >::type;

        template <int ...gathered>
        struct is {
            static_assert(equal<vector<x<gathered>...>, Gathered>::value, "");
        };
    };

    template <int n>
    struct Predicate {
        template <typename ToFold>
        struct apply
            : is_same<head_t<ToFold>, x<n>>
        { };
    };

    template <int n>
    struct until
        : until_pred<Predicate<n>>
    { };
};

struct tests :
    gather<>::until_pred<always<true_>>::is<>,

    gather<0>::until<0>::is<>,

    gather<0, 1>::until<0>::is<>,
    gather<0, 1>::until<1>::is<0>,

    gather<0, 1, 2>::until<0>::is<>,
    gather<0, 1, 2>::until<1>::is<0>,
    gather<0, 1, 2>::until<2>::is<0, 1>,

    gather<0, 1, 2, 3>::until<0>::is<>,
    gather<0, 1, 2, 3>::until<1>::is<0>,
    gather<0, 1, 2, 3>::until<2>::is<0, 1>,
    gather<0, 1, 2, 3>::until<3>::is<0, 1, 2>,

    gather<0, 1, 2, 3, 4>::until<0>::is<>,
    gather<0, 1, 2, 3, 4>::until<1>::is<0>,
    gather<0, 1, 2, 3, 4>::until<2>::is<0, 1>,
    gather<0, 1, 2, 3, 4>::until<3>::is<0, 1, 2>,
    gather<0, 1, 2, 3, 4>::until<4>::is<0, 1, 2, 3>
{ };


int main() { }
