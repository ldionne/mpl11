/*!
 * @file
 * This file contains unit tests for `boost::mpl11::integral_c`.
 */

#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>
#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;

static_assert(integral_c<int, 2>::value == 2, "");

static_assert(is_same<
    integral_c<int, 2>::type,
    integral_c<int, 2>
>::value, "");

static_assert(is_same<
    next<integral_c<int, 2>>::type,
    integral_c<int, 3>
>::value, "");

static_assert(is_same<
    prior<integral_c<int, 2>>::type,
    integral_c<int, 1>
>::value, "");

static_assert(is_same<
    integral_c<int, 2>::value_type, int
>::value, "");


int main() {
    int i = integral_c<int, 2>{};
    (void)i;
}
