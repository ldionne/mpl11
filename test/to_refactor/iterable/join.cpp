/*!
 * @file
 * Contains unit tests for `boost::mpl11::join`.
 */

#include <boost/mpl11/iterable/join.hpp>

#include <boost/mpl11/detail/iterable_test.hpp>


using namespace boost::mpl11;

template <int> struct x { struct type; };

template <int ...i>
using seq = detail::minimal_iterable<x<i>...>;

template <typename ...Iterables>
struct joining {
    template <int ...Joined>
    struct is
        : detail::iterable_test<
            join<Iterables...>,
            x<Joined>...
        >
    { };
};

template <int ...S1>
struct test_join :
    joining<seq<S1...>>::template is<S1...>,

    joining<seq<S1...>, seq<>>::template is<S1...>,
    joining<seq<S1...>, seq<0>>::template is<S1..., 0>,
    joining<seq<S1...>, seq<0, 1>>::template is<S1..., 0, 1>,

    joining<seq<S1...>, seq<>, seq<>>::template is<S1...>,
    joining<seq<S1...>, seq<>, seq<0>>::template is<S1..., 0>,
    joining<seq<S1...>, seq<>, seq<0, 1>>::template is<S1..., 0, 1>,

    joining<seq<S1...>, seq<0>, seq<>>::template is<S1..., 0>,
    joining<seq<S1...>, seq<0>, seq<1>>::template is<S1..., 0, 1>,
    joining<seq<S1...>, seq<0>, seq<1, 2>>::template is<S1..., 0, 1, 2>,

    joining<seq<S1...>, seq<0, 1>, seq<>>::template is<S1..., 0, 1>,
    joining<seq<S1...>, seq<0, 1>, seq<2>>::template is<S1..., 0, 1, 2>,
    joining<seq<S1...>, seq<0, 1>, seq<2, 3>>::template is<S1..., 0, 1, 2, 3>
{ };

struct tests :
    joining<>::is<>,
    test_join<>,
    test_join<9>,
    test_join<9, 8>,
    test_join<9, 8, 7>,
    test_join<9, 8, 7, 6>,
    joining<
        seq<0>, seq<1>, seq<>, seq<2, 3>, seq<>, seq<4, 5>, seq<6>, seq<>
    >::is<0, 1, 2, 3, 4, 5, 6>
{ };


int main() { }
