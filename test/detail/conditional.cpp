/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::conditional`.
 */

#include <boost/mpl11/detail/conditional.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using boost::mpl11::detail::conditional;
using boost::mpl11::detail::is_same;

static_assert(is_same<
    conditional<true, struct Then, struct Else>::type,
    struct Then
>::value, "");

static_assert(is_same<
    conditional<false, struct Then, struct Else>::type,
    struct Else
>::value, "");


int main() { }
