/*!
 * @file
 * Contains unit tests for `boost::mpl11::take`.
 */

#include <boost/mpl11/take.hpp>

#include <boost/mpl11/container.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/length.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;

template <int> struct x;

template <int ...i>
using sequence = test::wrapper<
    test::minimal_requirements<Sequence>, vector<x<i>...>
>;

template <int ...i>
using container = test::wrapper<
    test::minimal_requirements<Container>, vector<x<i>...>
>;

template <int N>
struct do_take {
    template <int ...seq>
    struct in {
        template <int ...kept>
        struct is {
            template <typename Kept>
            struct assertions {
                static_assert(equal<vector<x<kept>...>, Kept>::value, "");
                static_assert(is_empty<Kept>::value == (sizeof...(kept) == 0), "");
                static_assert(length<Kept>::value == sizeof...(kept), "");
            };

            static constexpr auto trigger_assertions =
                sizeof(assertions<take_c<N, sequence<seq...>>>) +
                sizeof(assertions<take_c_t<N, container<seq...>>>);
        };
    };
};

struct test_all :
    do_take<0>::in<>::is<>,
    do_take<1>::in<>::is<>,
    do_take<2>::in<>::is<>,

    do_take<0>::in<0>::is<>,
    do_take<1>::in<0>::is<0>,
    do_take<2>::in<0>::is<0>,

    do_take<0>::in<0, 1>::is<>,
    do_take<1>::in<0, 1>::is<0>,
    do_take<2>::in<0, 1>::is<0, 1>,
    do_take<3>::in<0, 1>::is<0, 1>,

    do_take<0>::in<0, 1, 2>::is<>,
    do_take<1>::in<0, 1, 2>::is<0>,
    do_take<2>::in<0, 1, 2>::is<0, 1>,
    do_take<3>::in<0, 1, 2>::is<0, 1, 2>,
    do_take<4>::in<0, 1, 2>::is<0, 1, 2>,

    do_take<0>::in<0, 1, 2, 3>::is<>,
    do_take<1>::in<0, 1, 2, 3>::is<0>,
    do_take<2>::in<0, 1, 2, 3>::is<0, 1>,
    do_take<3>::in<0, 1, 2, 3>::is<0, 1, 2>,
    do_take<4>::in<0, 1, 2, 3>::is<0, 1, 2, 3>
{ };


int main() { }
