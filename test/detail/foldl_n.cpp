/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::foldl_n`.
 */

#include <boost/mpl11/detail/foldl_n.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>

#include "../minimal_requirements.hpp"


using namespace boost::mpl11;
using detail::foldl_n;

template <int> struct x;

template <int ...i>
using sequence = test::wrapper<
    test::minimal_requirements<Sequence>, vector<x<i>...>
>;

template <int ...i>
struct gather {
    template <int n>
    struct first_n {
        template <typename Gathered, typename Iter>
        struct Accumulator
            : push_back<Gathered, deref_t<Iter>>
        { };

        using Gathered = typename foldl_n<
            n,
            begin_t<sequence<i...>>,
            vector<>,
            quote<Accumulator>
        >::type;

        template <int ...gathered>
        struct is {
            static_assert(equal<vector<x<gathered>...>, Gathered>::value, "");
        };
    };
};

struct tests :
    gather<>::first_n<0>::is<>,

    gather<0>::first_n<0>::is<>,
    gather<0>::first_n<1>::is<0>,

    gather<0, 1>::first_n<0>::is<>,
    gather<0, 1>::first_n<1>::is<0>,
    gather<0, 1>::first_n<2>::is<0, 1>,

    gather<0, 1, 2>::first_n<0>::is<>,
    gather<0, 1, 2>::first_n<1>::is<0>,
    gather<0, 1, 2>::first_n<2>::is<0, 1>,
    gather<0, 1, 2>::first_n<3>::is<0, 1, 2>,

    gather<0, 1, 2, 3>::first_n<0>::is<>,
    gather<0, 1, 2, 3>::first_n<1>::is<0>,
    gather<0, 1, 2, 3>::first_n<2>::is<0, 1>,
    gather<0, 1, 2, 3>::first_n<3>::is<0, 1, 2>,
    gather<0, 1, 2, 3>::first_n<4>::is<0, 1, 2, 3>,

    gather<0, 1, 2, 3, 4>::first_n<0>::is<>,
    gather<0, 1, 2, 3, 4>::first_n<1>::is<0>,
    gather<0, 1, 2, 3, 4>::first_n<2>::is<0, 1>,
    gather<0, 1, 2, 3, 4>::first_n<3>::is<0, 1, 2>,
    gather<0, 1, 2, 3, 4>::first_n<4>::is<0, 1, 2, 3>,
    gather<0, 1, 2, 3, 4>::first_n<5>::is<0, 1, 2, 3, 4>
{ };


int main() { }
