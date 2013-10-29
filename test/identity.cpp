/*!
 * @file
 * Contains unit tests for `boost::mpl11::identity`.
 */

#include <boost/mpl11/identity.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;

static_assert(detail::is_same<
    struct any_type, identity<struct any_type>::type
>::value, "");


int main() { }
