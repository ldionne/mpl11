/*!
 * @file
 * Contains unit tests for `boost::mpl11::empty_sequence`.
 */

#include <boost/mpl11/empty_sequence.hpp>

#include <boost/mpl11/detail/sequence_test.hpp>


using namespace boost::mpl11;

struct tests :
    detail::sequence_test<empty_sequence>
{ };


int main() { }
