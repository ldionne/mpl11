/*!
 * @file
 * Contains unit tests for `boost::mpl11::integral_c`.
 */

#include <boost/mpl11/integral_c.hpp>

#include <boost/mpl11/detail/test_integral_constant.hpp>


using namespace boost::mpl11;

struct instantiate_test
    : detail::test_integral_constant<integral_c>
{ };


int main() { }
