/*!
 * @file
 * Contains unit tests for `boost::mpl11::is_placeholder_expression`.
 */

#include <boost/mpl11/is_placeholder_expression.hpp>

#include "placeholders.hpp"


using namespace boost::mpl11;

template <typename ...> struct pack;

static_assert(!is_placeholder_expression<struct a0>::type::value, "");
static_assert(!is_placeholder_expression<pack<>>::type::value, "");
static_assert(!is_placeholder_expression<pack<struct a0>>::type::value, "");

template <typename Placeholder>
void test_placeholder() {
    static_assert(is_placeholder_expression<
        Placeholder
    >::type::value, "");
    static_assert(is_placeholder_expression<
        pack<Placeholder>
    >::type::value, "");
    static_assert(is_placeholder_expression<
        pack<Placeholder, pack<>>
    >::type::value, "");
    static_assert(is_placeholder_expression<
        pack<pack<Placeholder>>
    >::type::value, "");
}

template <typename = placeholder::non_template>
struct with_default_param;


int main() {
    test_placeholder<with_default_param<>>();

    test_placeholder<placeholder::non_template>();

    test_placeholder<placeholder::variadic<>>();
    test_placeholder<placeholder::variadic<struct a0>>();
    test_placeholder<placeholder::variadic<struct a0, struct a1>>();

    test_placeholder<placeholder::unary<struct a0>>();

    test_placeholder<placeholder::binary<struct a0, struct a1>>();
}
