/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::dependent`.
 */

#include <boost/mpl11/detail/dependent.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::dependent;
using detail::std_is_same;

template <typename T>
struct never_instantiated {
    static_assert(dependent<T>::value(false), "");
    using would_fail = typename dependent<T>::template
                       type<int>::because_int_has_no_such_member_type;
};

struct x; struct y;
struct foo;
static_assert(std_is_same<dependent<>::type<foo>, foo>::value, "");
static_assert(std_is_same<dependent<x>::type<foo>, foo>::value, "");
static_assert(std_is_same<dependent<x, y>::type<foo>, foo>::value, "");

static_assert(dependent<>::value(2) == 2, "");
static_assert(dependent<x>::value(0) == 0, "");
static_assert(dependent<x, y>::value(1) == 1, "");

int main() { }
