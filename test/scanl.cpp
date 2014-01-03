/*!
 * @file
 * Contains unit tests for `boost::mpl11::scanl`.
 */

#include <boost/mpl11/scanl.hpp>

#include <boost/mpl11/list.hpp>
#include <boost/mpl11/quote.hpp>
#include "sequence_test.hpp"


using namespace mpl11_test;
using namespace boost::mpl11;

template <int ...> struct state;
template <int> struct x;

template <typename State, typename X>
struct state_append;

template <int ...State, int X>
struct state_append<state<State...>, x<X>> {
    using type = state<State..., X>;
};

template <int First, int ...I>
struct scanning {
    template <typename ...States>
    struct is :
        forward_sequence_test<      scanl_t<quote<state_append>, state<First>, list<x<I>...>>, States...>,
        finite_sequence_test<       scanl_t<quote<state_append>, state<First>, list<x<I>...>>, States...>,
        bidirectional_sequence_test<scanl_t<quote<state_append>, state<First>, list<x<I>...>>, States...>,
        random_access_sequence_test<scanl_t<quote<state_append>, state<First>, list<x<I>...>>, States...>
    { };
};


struct tests :
    scanning<0>::is<
        state<0>
    >,

    scanning<0, 1>::is<
        state<0>,
        state<0, 1>
    >,

    scanning<0, 1, 2>::is<
        state<0>,
        state<0, 1>,
        state<0, 1, 2>
    >,

    scanning<0, 1, 2, 3>::is<
        state<0>,
        state<0, 1>,
        state<0, 1, 2>,
        state<0, 1, 2, 3>
    >,

    scanning<0, 1, 2, 3, 4>::is<
        state<0>,
        state<0, 1>,
        state<0, 1, 2>,
        state<0, 1, 2, 3>,
        state<0, 1, 2, 3, 4>
    >,

    scanning<0, 1, 2, 3, 4, 5>::is<
        state<0>,
        state<0, 1>,
        state<0, 1, 2>,
        state<0, 1, 2, 3>,
        state<0, 1, 2, 3, 4>,
        state<0, 1, 2, 3, 4, 5>
    >
{ };


int main() { }
