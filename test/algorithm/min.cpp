/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::min`.
 */

#include <boost/mpl11/algorithm/min.hpp>

#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


using namespace boost::mpl11;
using algorithm::min;

static_assert(equal_to<
    min<int_<1>, int_<0>>::type,
    int_<0>
>::type::value, "");

static_assert(equal_to<
    min<int_<0>, int_<-3>, int_<2>>::type,
    int_<-3>
>::type::value, "");


int main() { }
