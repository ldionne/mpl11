/*!
 * @file
 * Contains unit tests for `boost::mpl11::id`.
 */

#include <boost/mpl11/id.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using namespace detail;

struct t { struct type; };

static_assert(is_same<t::type, id<t>::type>::value, "");
static_assert(is_same<t::type, id_t<t>>::value, "");

// Make sure id and id_t can be passed as template template arguments.
template <template <typename ...> class Id, typename T>
struct specialize_with {
    using type = Id<T>;
};
static_assert(is_same<specialize_with<id_t, t>::type, id_t<t>>::value, "");
static_assert(is_same<specialize_with<id, t>::type, id<t>>::value, "");


int main() { }
