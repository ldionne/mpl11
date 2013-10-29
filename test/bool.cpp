/*!
 * @file
 * Contains unit tests for `boost::mpl11::bool_`.
 */

#include <boost/mpl11/bool.hpp>

#include <boost/mpl11/detail/test_boolean.hpp>


using namespace boost::mpl11;

struct instantiate_test
    : detail::test_boolean<true_, false_>
{ };


int main() { }
