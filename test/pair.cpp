/*!
 * @file
 * Contains unit tests for `boost::mpl11::pair`.
 */

#include <boost/mpl11/pair.hpp>

#include <boost/mpl11/detail/test_couple.hpp>


using namespace boost::mpl11;

struct instantiate_test
    : detail::test_couple<pair>
{ };


int main() { }
