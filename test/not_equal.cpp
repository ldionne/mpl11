/*!
 * @file
 * Contains unit tests for `boost::mpl11::not_equal`'s default implementation.
 */

#include <boost/mpl11/not_equal.hpp>


using namespace boost::mpl11;

static_assert( not_equal<struct x, struct y>::value, "");
static_assert(!not_equal<struct x, struct x>::value, "");


int main() { }
