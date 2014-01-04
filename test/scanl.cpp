/*!
 * @file
 * Contains unit tests for `boost::mpl11::scanl`.
 */

#include <boost/mpl11/scanl.hpp>

#include <boost/mpl11/detail/sequence_test.hpp>


using namespace boost::mpl11;

template <int> struct x;

template <int ...I>
using ilist = detail::minimal_sequence<x<I>...>;

struct append {
    template <typename Seq, typename X>
    struct apply;

    template <typename ...T, typename X>
    struct apply<detail::minimal_sequence<T...>, X> {
        using type = detail::minimal_sequence<T..., X>;
    };
};

template <int State, int ...ToFold>
struct scanning {
    template <typename ...Result>
    struct is
        : detail::sequence_test<
            scanl_t<append, ilist<State>, ilist<ToFold...>>,
            Result...
        >
    { };
};

struct tests :
    scanning<0>::is<
        ilist<0>
    >,

    scanning<0, 1>::is<
        ilist<0>,
        ilist<0, 1>
    >,

    scanning<0, 1, 2>::is<
        ilist<0>,
        ilist<0, 1>,
        ilist<0, 1, 2>
    >,

    scanning<0, 1, 2, 3>::is<
        ilist<0>,
        ilist<0, 1>,
        ilist<0, 1, 2>,
        ilist<0, 1, 2, 3>
    >,

    scanning<0, 1, 2, 3, 4>::is<
        ilist<0>,
        ilist<0, 1>,
        ilist<0, 1, 2>,
        ilist<0, 1, 2, 3>,
        ilist<0, 1, 2, 3, 4>
    >,

    scanning<0, 1, 2, 3, 4, 5>::is<
        ilist<0>,
        ilist<0, 1>,
        ilist<0, 1, 2>,
        ilist<0, 1, 2, 3>,
        ilist<0, 1, 2, 3, 4>,
        ilist<0, 1, 2, 3, 4, 5>
    >
{ };


int main() { }
