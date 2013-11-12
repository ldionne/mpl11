/*!
 * @file
 * Contains unit tests for `boost::mpl11::equal`'s default implementation.
 */

#include <boost/mpl11/equal.hpp>


using namespace boost::mpl11;

static_assert( equal<struct x, struct x>::value, "");
static_assert(!equal<struct x, struct y>::value, "");


int main() { }
