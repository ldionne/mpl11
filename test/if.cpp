/*!
 * @file
 * Contains unit tests for `boost::mpl11::if_`.
 */

#include <boost/mpl11/if.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

static_assert(is_same<
    if_c<true, struct Then, struct Else>::type, struct Then
>::value, "");

static_assert(is_same<
    if_c<false, struct Then, struct Else>::type, struct Else
>::value, "");


int main() { }
