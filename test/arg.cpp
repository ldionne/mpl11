/*!
 * @file
 * Contains unit tests for `boost::mpl11::arg`.
 */

#include <boost/mpl11/arg.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct a0; struct a1; struct a2; struct a3; struct a4; struct a5;

static_assert(is_same<apply_t<arg<0>, a0>, a0>::value, "");
static_assert(is_same<apply_t<arg<0>, a0, a1>, a0>::value, "");
static_assert(is_same<apply_t<arg<0>, a0, a1, a2>, a0>::value, "");

static_assert(is_same<apply_t<arg<1>, a0, a1>, a1>::value, "");
static_assert(is_same<apply_t<arg<1>, a0, a1, a2>, a1>::value, "");
static_assert(is_same<apply_t<arg<1>, a0, a1, a2, a3>, a1>::value, "");

static_assert(is_same<apply_t<arg<2>, a0, a1, a2>, a2>::value, "");
static_assert(is_same<apply_t<arg<2>, a0, a1, a2, a3>, a2>::value, "");
static_assert(is_same<apply_t<arg<2>, a0, a1, a2, a3, a4>, a2>::value, "");

static_assert(is_same<apply_t<arg<3>, a0, a1, a2, a3>, a3>::value, "");
static_assert(is_same<apply_t<arg<3>, a0, a1, a2, a3, a4>, a3>::value, "");
static_assert(is_same<apply_t<arg<3>, a0, a1, a2, a3, a4, a5>, a3>::value, "");


int main() { }
