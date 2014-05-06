/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::inherit`.
 */

#include <boost/mpl11/detail/inherit.hpp>

#include <type_traits>


using boost::mpl11::detail::inherit;
using std::is_base_of;

template <int> struct x { };

static_assert(!is_base_of<x<0>, inherit<>>::value, "");

static_assert(is_base_of<x<0>, inherit<x<0>>>::value, "");
static_assert(!is_base_of<x<1>, inherit<x<0>>>::value, "");

static_assert(is_base_of<x<0>, inherit<x<0>, x<1>>>::value, "");
static_assert(is_base_of<x<1>, inherit<x<0>, x<1>>>::value, "");
static_assert(!is_base_of<x<2>, inherit<x<0>, x<1>>>::value, "");


int main() { }
