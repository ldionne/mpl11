/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::is_same`.
 */

#include <boost/mpl11/detail/is_same.hpp>


using boost::mpl11::detail::is_same;

static_assert(is_same<int, int>::type::value, "");
static_assert(!is_same<int, int&>::type::value, "");
static_assert(!is_same<int, int volatile>::type::value, "");
static_assert(!is_same<int, int const>::type::value, "");
static_assert(!is_same<int, int const volatile>::type::value, "");
static_assert(!is_same<int, float>::type::value, "");


int main() { }
