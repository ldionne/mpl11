/*!
 * @file
 * Contains unit tests for `boost::mpl11::identity`.
 */

#include <boost/mpl11/identity.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using namespace detail;

struct t;

static_assert(is_same<t, identity<t>::type>::value, "");
static_assert(is_same<t, identity_t<t>>::value, "");

// Make sure identity_t can be passed as a template template argument.
template <template <typename ...> class Id>
struct apply_to_t {
    using type = Id<t>;
};
static_assert(is_same<apply_to_t<identity_t>::type, t>::value, "");


int main() { }
