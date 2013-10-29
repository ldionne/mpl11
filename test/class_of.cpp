/*!
 * @file
 * Contains unit tests for `boost::mpl11::class_of`.
 */

#include <boost/mpl11/class_of.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct some_type { struct mpl_class; };

static_assert(is_same<
    class_of<some_type>::type,
    some_type::mpl_class
>::value, "");


int main() { }
