/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::dependent_on`.
 */

#include <boost/mpl11/detail/dependent_on.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::dependent_on;
using detail::is_same;

template <typename T>
struct never_instantiated {
    static_assert(dependent_on<T>::template value<bool, false>(), "");
    using would_fail = typename dependent_on<T>::template
                            type<int>::because_int_has_no_such_member_type;
};

static_assert(is_same<
    dependent_on<struct anything>::type<struct some_type>,
    struct some_type
>::value, "");

static_assert(dependent_on<struct anything>::value<int, 0>() == 0, "");
static_assert(dependent_on<struct anything>::value<int, 1>() == 1, "");
static_assert(dependent_on<struct anything>::value<int, 2>() == 2, "");


int main() { }
