/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::tp_conditional`.
 */

#include <boost/mpl11/detail/tp_conditional.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::tp_conditional;
using detail::is_same;

template <typename ...> struct Then;
template <typename ...> struct Else;
struct x; struct y;

static_assert(is_same<
    tp_conditional<true, Then, Else>::type<>,
    Then<>
>::value, "");
static_assert(is_same<
    tp_conditional<true, Then, Else>::type<x>,
    Then<x>
>::value, "");
static_assert(is_same<
    tp_conditional<true, Then, Else>::type<x, y>,
    Then<x, y>
>::value, "");

static_assert(is_same<
    tp_conditional<false, Then, Else>::type<>,
    Else<>
>::value, "");
static_assert(is_same<
    tp_conditional<false, Then, Else>::type<x>,
    Else<x>
>::value, "");
static_assert(is_same<
    tp_conditional<false, Then, Else>::type<x, y>,
    Else<x, y>
>::value, "");


int main() { }
