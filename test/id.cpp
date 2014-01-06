/*!
 * @file
 * Contains unit tests for `boost::mpl11::id`.
 */

#include <boost/mpl11/id.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using namespace detail;

struct t;

static_assert(is_same<t, id<t>::type>::value, "");
static_assert(is_same<t, id_t<t>>::value, "");

// Make sure identity_t can be passed as a template template argument.
template <template <typename ...> class Id>
struct apply_to_t {
    using type = Id<t>;
};
static_assert(is_same<apply_to_t<id_t>::type, t>::value, "");


int main() { }
