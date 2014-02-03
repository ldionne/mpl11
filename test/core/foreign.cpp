/*!
 * @file
 * Contains unit tests for `boost::mpl11::Foreign`.
 */

#include <boost/mpl11/core.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

// Test conversion to `Foreign`.
struct x { struct type; };
static_assert(std_is_same<
    Foreign::from<undefined>::type::apply<x>::type,
    x::type
>::value, "");

// Test `common_datatype` specialization.
static_assert(std_is_same<
    common_datatype<Foreign, undefined>::type,
    Foreign
>::value, "");

static_assert(std_is_same<
    common_datatype<undefined, Foreign>::type,
    Foreign
>::value, "");


int main() { }
