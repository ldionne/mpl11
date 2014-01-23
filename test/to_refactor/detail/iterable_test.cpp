/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::iterable_test`.
 */

#include <boost/mpl11/detail/iterable_test.hpp>


using namespace boost::mpl11;
using namespace detail;

template <int> struct x { struct type; };

template <int ...i>
struct test_minimal
    : iterable_test<minimal_iterable<x<i>...>, x<i>...>
{ };

struct tests :
    test_minimal<>,
    test_minimal<0>,
    test_minimal<0, 1>,
    test_minimal<0, 1, 2>,
    test_minimal<0, 1, 2, 3>,
    test_minimal<0, 1, 2, 3, 4>,
    test_minimal<0, 1, 2, 3, 4, 5>,
    test_minimal<0, 1, 2, 3, 4, 5, 6>,
    test_minimal<0, 1, 2, 3, 4, 5, 6, 7>
{ };


int main() { }
