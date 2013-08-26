/*!
 * @file
 * This file contains unit tests for `boost::mpl11::detail::tag_dispatched`.
 */

#include <boost/mpl11/detail/tag_dispatched.hpp>

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;
using detail::tag_dispatched;

struct test_tag;

namespace boost { namespace mpl11 {
    template <typename ...MoreTags>
    struct dispatch<test_tag, MoreTags...> {
        template <typename ...Args>
        struct apply { struct type; };
    };
}}

static_assert(is_same<
    tag_dispatched<test_tag>::with_default<>::type,
    dispatch<test_tag>::apply<test_tag>::type
>::value, "");

static_assert(is_same<
    tag_dispatched<struct unknown_tag>::with_default<always<struct T>>::type,
    struct T
>::value, "");


int main() { }
