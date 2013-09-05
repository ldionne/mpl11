/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::max`.
 */

#include <boost/mpl11/algorithm/max.hpp>

#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>


using namespace boost::mpl11;
using algorithm::max;
using intrinsic::equal_to;

static_assert(equal_to<
    max<int_<1>, int_<0>>::type,
    int_<1>
>::type::value, "");

static_assert(equal_to<
    max<int_<0>, int_<1>, int_<2>>::type,
    int_<2>
>::type::value, "");


int main() { }
