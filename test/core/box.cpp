/*!
 * @file
 * Contains unit tests for `boost::mpl11::box`.
 */

#include <boost/mpl11/core.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

static_assert(!std_is_same<box<undefined>, undefined>::value, "");
static_assert( std_is_same<box<undefined>::type, undefined>::value, "");


int main() { }
