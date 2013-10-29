/*!
 * @file
 * Contains unit tests for `boost::mpl11::always`.
 */

#include <boost/mpl11/always.hpp>

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

static_assert(is_same<
    apply_wrap<always<struct anything>>::type,
    struct anything
>::value, "");

static_assert(is_same<
    apply_wrap<always<struct anything>, struct x>::type,
    struct anything
>::value, "");

static_assert(is_same<
    apply_wrap<always<struct anything>, struct x, struct y>::type,
    struct anything
>::value, "");

static_assert(is_same<
    apply_wrap<always<struct anything>, struct x, struct y, struct z>::type,
    struct anything
>::value, "");


int main() { }
