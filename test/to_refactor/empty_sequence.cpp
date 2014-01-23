/*!
 * @file
 * Contains unit tests for `boost::mpl11::empty_sequence`.
 */

#include <boost/mpl11/empty_sequence.hpp>

#include <boost/mpl11/detail/iterable_test.hpp>


using namespace boost::mpl11;

struct tests :
    detail::iterable_test<empty_sequence>
{ };


int main() { }
