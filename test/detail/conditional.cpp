/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::conditional`.
 */

#include <boost/mpl11/detail/conditional.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using namespace detail;

struct Then; struct Else;
static_assert(is_same<conditional<true,  Then, Else>::type, Then>::value, "");
static_assert(is_same<conditional<false, Then, Else>::type, Else>::value, "");


int main() { }
