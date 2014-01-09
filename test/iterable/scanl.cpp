/*!
 * @file
 * Contains unit tests for `boost::mpl11::scanl`.
 */

#include <boost/mpl11/iterable/scanl.hpp>

#include <boost/mpl11/detail/iterable_test.hpp>


using namespace boost::mpl11;

template <int> struct x;

template <int ...I>
using ilist = detail::minimal_iterable<x<I>...>;

struct append {
    template <typename Seq, typename X>
    struct apply;

    template <typename ...T, typename X>
    struct apply<detail::minimal_iterable<T...>, X> {
        using type = detail::minimal_iterable<T..., X>;
    };
};

template <int State, int ...ToFold>
struct scanning {
    template <typename ...Result>
    struct is
        : detail::iterable_test<
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
