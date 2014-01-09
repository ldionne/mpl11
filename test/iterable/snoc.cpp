/*!
 * @file
 * Contains unit tests for `boost::mpl11::snoc`.
 */

#include <boost/mpl11/iterable/snoc.hpp>

#include <boost/mpl11/detail/iterable_test.hpp>


using namespace boost::mpl11;

template <int> struct x;

template <int Last, int ...Init>
struct test_snoc
    : detail::iterable_test<
        snoc_t<detail::minimal_iterable<x<Init>...>, x<Last>>,
        x<Init>..., x<Last>
    >
{ };

struct tests :
    test_snoc<0>,
    test_snoc<0, 1>,
    test_snoc<0, 1, 2>,
    test_snoc<0, 1, 2, 3>,
    test_snoc<0, 1, 2, 3, 4>
{ };


int main() { }
