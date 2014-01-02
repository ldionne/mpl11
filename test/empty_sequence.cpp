/*!
 * @file
 * Contains unit tests for `boost::mpl11::empty_sequence`.
 */

#include <boost/mpl11/empty_sequence.hpp>

#include "sequence_test.hpp"


using namespace mpl11_test;
using boost::mpl11::empty_sequence_t;

struct tests :
    forward_sequence_test<empty_sequence_t>,
    finite_sequence_test<empty_sequence_t>,
    bidirectional_sequence_test<empty_sequence_t>,
    random_access_sequence_test<empty_sequence_t>
{ };


int main() { }
