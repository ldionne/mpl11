/*!
 * @file
 * Contains unit tests for `boost::mpl11::always`.
 */

#include <boost/mpl11/always.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct a;
struct x; struct y; struct z;

static_assert(is_same<a, apply_t<always<a>>>::value, "");
static_assert(is_same<a, apply_t<always<a>, x>>::value, "");
static_assert(is_same<a, apply_t<always<a>, x, y>>::value, "");
static_assert(is_same<a, apply_t<always<a>, x, y, z>>::value, "");


int main() { }
