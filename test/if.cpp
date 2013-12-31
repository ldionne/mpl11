/*!
 * @file
 * Contains unit tests for `boost::mpl11::if_`.
 */

#include <boost/mpl11/if.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct Then; struct Else;

// test if_
struct yes { struct type { static constexpr bool value = true; }; };
struct no { struct type { static constexpr bool value = false; }; };
static_assert(is_same<if_<yes, Then, Else>::type, Then>::value, "");
static_assert(is_same<if_<no, Then, Else>::type, Else>::value, "");

// test if_c
static_assert(is_same<if_c<true, Then, Else>::type, Then>::value, "");
static_assert(is_same<if_c<false, Then, Else>::type, Else>::value, "");


int main() { }
