/*!
 * @file
 * Contains unit tests for `boost::mpl11::integral_c`.
 */

#include <boost/mpl11/integral_c.hpp>

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/prior.hpp>
#include <boost/mpl11/equal_to.hpp>


using namespace boost::mpl11;

// ::value
static_assert(integral_c<int, 2>::value == 2, "");

// ::type
static_assert(equal_to<
    integral_c<int, 2>::type,
    integral_c<int, 2>
>::type::value, "");

// ::value_type
static_assert(equal_to<
    integral_c<int, 2>::value_type, int
>::type::value, "");

// next
static_assert(equal_to<
    next<integral_c<int, 2>>::type,
    integral_c<int, 3>
>::type::value, "");

// prior
static_assert(equal_to<
    prior<integral_c<int, 2>>::type,
    integral_c<int, 1>
>::type::value, "");

// deref
static_assert(equal_to<
    deref<integral_c<int, 2>>::type,
    integral_c<int, 2>
>::type::value, "");


int main() {
    int i = integral_c<int, 2>{};
    (void)i;
}
