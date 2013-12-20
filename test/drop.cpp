/*!
 * @file
 * Contains unit tests for `boost::mpl11::drop`.
 */

#include <boost/mpl11/drop.hpp>

#include <boost/mpl11/container.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/size.hpp>
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
struct do_drop {
    template <int ...seq>
    struct from {
        template <int ...kept>
        struct is {
            template <typename Kept>
            struct assertions {
                static_assert(equal<vector<x<kept>...>, Kept>::value, "");
                static_assert(is_empty<Kept>::value == (sizeof...(kept) == 0), "");
                static_assert(size<Kept>::value == sizeof...(kept), "");
            };

            static constexpr auto trigger_assertions =
                sizeof(assertions<drop_c<N, sequence<seq...>>>) +
                sizeof(assertions<drop_c_t<N, container<seq...>>>);
        };
    };
};

struct test_all :
    do_drop<0>::from<>::is<>,
    do_drop<1>::from<>::is<>,
    do_drop<2>::from<>::is<>,

    do_drop<0>::from<0>::is<0>,
    do_drop<1>::from<0>::is<>,
    do_drop<2>::from<0>::is<>,

    do_drop<0>::from<0, 1>::is<0, 1>,
    do_drop<1>::from<0, 1>::is<1>,
    do_drop<2>::from<0, 1>::is<>,
    do_drop<3>::from<0, 1>::is<>,

    do_drop<0>::from<0, 1, 2>::is<0, 1, 2>,
    do_drop<1>::from<0, 1, 2>::is<1, 2>,
    do_drop<2>::from<0, 1, 2>::is<2>,
    do_drop<3>::from<0, 1, 2>::is<>,
    do_drop<4>::from<0, 1, 2>::is<>,

    do_drop<0>::from<0, 1, 2, 3>::is<0, 1, 2, 3>,
    do_drop<1>::from<0, 1, 2, 3>::is<1, 2, 3>,
    do_drop<2>::from<0, 1, 2, 3>::is<2, 3>,
    do_drop<3>::from<0, 1, 2, 3>::is<3>,
    do_drop<4>::from<0, 1, 2, 3>::is<>
{ };


int main() { }
