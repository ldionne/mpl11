/*!
 * @file
 * Contains unit tests for `boost::mpl11::cons`.
 */

#include <boost/mpl11/iterable/cons.hpp>

#include <boost/mpl11/detail/iterable_test.hpp>


using namespace boost::mpl11;

template <int> struct x;

template <int Head, int ...Tail>
struct test_cons
    : detail::iterable_test<
        cons_t<x<Head>, detail::minimal_iterable<x<Tail>...>>,
        x<Head>, x<Tail>...
    >
{ };

struct tests :
    test_cons<0>,
    test_cons<0, 1>,
    test_cons<0, 1, 2>,
    test_cons<0, 1, 2, 3>,
    test_cons<0, 1, 2, 3, 4>
{ };


int main() { }
