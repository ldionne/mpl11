/*!
 * @file
 * Contains unit tests for `boost::mpl11::datatype`.
 */

#include <boost/mpl11/core.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

struct with_nested_datatype { struct mpl_datatype; };
static_assert(std_is_same<
    datatype<with_nested_datatype>::type,
    with_nested_datatype::mpl_datatype
>::value, "");

struct without_nested_datatype { };
static_assert(std_is_same<
    datatype<without_nested_datatype>::type,
    Foreign
>::value, "");

static_assert(std_is_same<
    datatype<void>::type,
    Foreign
>::value, "");


int main() { }
