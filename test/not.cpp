/*!
 * @file
 * Contains unit tests for `boost::mpl11::not_c`.
 */

#include <boost/mpl11/not.hpp>


using namespace boost::mpl11;

static_assert(!not_c<true>::value, "");
static_assert( not_c<false>::value, "");


int main() { }
