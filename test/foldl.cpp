/*!
 * @file
 * Contains unit tests for `boost::mpl11::foldl`.
 */

#include <boost/mpl11/foldl.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/list.hpp>
#include <boost/mpl11/quote.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <int> struct x;
template <int ...> struct state;

template <typename, typename> struct fold_state;
template <int ...S, int X>
struct fold_state<state<S...>, x<X>> { using type = state<S..., X>; };

template <int ...i>
struct test_with {
    static_assert(is_same<
        foldl_t<quote<fold_state>, state<>, list<x<i>...>>,
        state<i...>
    >::value, "");
};

struct tests :
    test_with<>,
    test_with<0>,
    test_with<0, 1>,
    test_with<0, 1, 2>,
    test_with<0, 1, 2, 3>,
    test_with<0, 1, 2, 3, 4>,
    test_with<0, 1, 2, 3, 4, 5>,
    test_with<0, 1, 2, 3, 4, 5, 6>,
    test_with<0, 1, 2, 3, 4, 5, 6, 7>,
    test_with<0, 1, 2, 3, 4, 5, 6, 7, 8>,
    test_with<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>
{ };


int main() { }
