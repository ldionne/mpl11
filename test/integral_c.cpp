/*!
 * @file
 * Contains unit tests for `boost::mpl11::integral_c`.
 */

#include <boost/mpl11/integral_c.hpp>

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/intrinsic/category_of.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>


using namespace boost::mpl11;
using namespace intrinsic;
using detail::is_same;

// ::value
static_assert(integral_c<int, 2>::value == 2, "");

// ::type
static_assert(is_same<
    integral_c<int, 2>::type,
    integral_c<int, 2>
>::value, "");

// ::value_type
static_assert(is_same<
    integral_c<int, 2>::value_type, int
>::value, "");

// next
static_assert(is_same<
    next<integral_c<int, 2>>::type,
    integral_c<int, 3>
>::value, "");

// prior
static_assert(is_same<
    prior<integral_c<int, 2>>::type,
    integral_c<int, 1>
>::value, "");

// deref
static_assert(is_same<
    deref<integral_c<int, 2>>::type,
    integral_c<int, 2>
>::value, "");

// category_of
static_assert(is_same<
    category_of<integral_c<int, 2>>::type,
    category::integral_constant
>::value, "");


int main() {
    int i = integral_c<int, 2>{};
    (void)i;
}
