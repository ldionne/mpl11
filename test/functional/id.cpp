/*!
 * @file
 * Contains unit tests for `boost::mpl11::id`.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

struct t;

static_assert(std_is_same<t, id<box<t>>::type>::value, "");

// Make sure id can be passed as a template template argument.
template <template <typename ...> class Id, typename T>
struct specialize_with {
    using type = Id<T>;
};
static_assert(std_is_same<
    specialize_with<id, t>::type,
    id<t>
>::value, "");


int main() { }
