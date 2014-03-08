/*!
 * @file
 * Contains unit tests for `boost::mpl11::rsect` and `boost::mpl11::lsect`.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

template <typename x, typename y>
struct op { struct type; };

struct x;
struct y;

static_assert(std_is_same<
    lsect_<x, op>::apply<y>::type,
    op<x, y>::type
>::value, "");

static_assert(std_is_same<
    rsect_<op, y>::apply<x>::type,
    op<x, y>::type
>::value, "");


int main() { }
