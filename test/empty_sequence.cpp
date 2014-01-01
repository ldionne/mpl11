/*!
 * @file
 * Contains unit tests for `boost::mpl11::empty_sequence`.
 */

#include <boost/mpl11/empty_sequence.hpp>

#include "sequence_test.hpp"


using namespace mpl11_test;
using boost::mpl11::empty_sequence;

struct tests :
    forward_sequence_test<empty_sequence>,
    finite_sequence_test<empty_sequence>,
    bidirectional_sequence_test<empty_sequence>,
    random_access_sequence_test<empty_sequence>
{ };


int main() { }
