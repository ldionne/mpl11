/*!
 * @file
 * Contains unit tests for `boost::mpl11::Foreign`.
 */

#include <boost/mpl11/core.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

struct x;
struct y;

/////////////////////////////////
// Test conversion to `Foreign`.
/////////////////////////////////
static_assert(!std_is_same<
    cast<undefined, Foreign>::type::apply<x>::type,
    cast<undefined, Foreign>::type::apply<y>::type
>::value, "");

static_assert(std_is_same<
    datatype<cast<undefined, Foreign>::type::apply<x>::type>::type,
    Foreign
>::value, "");

static_assert(std_is_same<
    cast<Foreign, Foreign>::type::apply<x>::type,
    x
>::value, "");


int main() { }
