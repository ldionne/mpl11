/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::std_conditional`.
 */

#include <boost/mpl11/detail/std_conditional.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using namespace detail;

struct Then; struct Else;
static_assert(std_is_same<
    std_conditional<true,  Then, Else>::type,
    Then
>::value, "");

static_assert(std_is_same<
    std_conditional<false, Then, Else>::type,
    Else
>::value, "");


int main() { }
