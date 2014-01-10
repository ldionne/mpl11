/*!
 * @file
 * Contains unit tests for `boost::mpl11::scanl`.
 */

#include <boost/mpl11/iterable/scanl.hpp>

#include <boost/mpl11/detail/iterable_test.hpp>
#include <boost/mpl11/iterable/snoc.hpp>
#include <boost/mpl11/quote.hpp>


using namespace boost::mpl11;

template <int> struct x { struct type; };

template <int ...i>
using seq = detail::minimal_iterable<x<i>...>;

template <int State, int ...ToFold>
struct scanning {
    template <typename ...Result>
    struct is
        : detail::iterable_test<
            scanl<quote<snoc>, seq<State>, seq<ToFold...>>,
            Result...
        >
    { };
};

struct tests :
    scanning<0>::is<
        seq<0>
    >,

    scanning<0, 1>::is<
        seq<0>,
        seq<0, 1>
    >,

    scanning<0, 1, 2>::is<
        seq<0>,
        seq<0, 1>,
        seq<0, 1, 2>
    >,

    scanning<0, 1, 2, 3>::is<
        seq<0>,
        seq<0, 1>,
        seq<0, 1, 2>,
        seq<0, 1, 2, 3>
    >,

    scanning<0, 1, 2, 3, 4>::is<
        seq<0>,
        seq<0, 1>,
        seq<0, 1, 2>,
        seq<0, 1, 2, 3>,
        seq<0, 1, 2, 3, 4>
    >,

    scanning<0, 1, 2, 3, 4, 5>::is<
        seq<0>,
        seq<0, 1>,
        seq<0, 1, 2>,
        seq<0, 1, 2, 3>,
        seq<0, 1, 2, 3, 4>,
        seq<0, 1, 2, 3, 4, 5>
    >
{ };


int main() { }
