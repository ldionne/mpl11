/*!
 * @file
 * Contains unit tests for `boost::mpl11::common_datatype`.
 */

#include <boost/mpl11/core.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

struct A; struct B; struct Common;

namespace boost { namespace mpl11 {
    template <>
    struct common_datatype<A, B> {
        using type = Common;
    };
}}

static_assert(std_is_same<
    common_datatype<A, B>::type,
    Common
>::value, "");

static_assert(std_is_same<
    common_datatype<B, A>::type,
    Common
>::value, "");


int main() { }
