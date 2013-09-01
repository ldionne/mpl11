/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::tag_dispatched`.
 */

#include <boost/mpl11/detail/tag_dispatched.hpp>

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tag_of.hpp>


using namespace boost::mpl11;
using detail::tag_dispatched;
using detail::is_same;

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
    dispatch<test_tag>::apply<>::type
>::value, "");

struct a0; struct a1;
static_assert(is_same<
    tag_dispatched<test_tag, a0, a1>::with_default<>::type,
    dispatch<test_tag, tag_of<a0>::type, tag_of<a1>::type>::apply<a0, a1>::type
>::value, "");

static_assert(is_same<
    tag_dispatched<struct unknown_tag>::with_default<always<a0>>::type,
    a0
>::value, "");


int main() { }
