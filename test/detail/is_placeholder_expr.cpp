/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::is_placeholder_expr`.
 */

#include <boost/mpl11/detail/is_placeholder_expr.hpp>

#include "placeholders.hpp"


using namespace boost::mpl11;
using detail::is_placeholder_expr;

template <typename ...> struct pack;

static_assert(!is_placeholder_expr<struct a0>::value, "");
static_assert(!is_placeholder_expr<pack<>>::value, "");
static_assert(!is_placeholder_expr<pack<struct a0>>::value, "");

template <typename Placeholder>
struct test_one {
    static_assert(is_placeholder_expr<
        Placeholder
    >::value, "");
    static_assert(is_placeholder_expr<
        pack<Placeholder>
    >::value, "");
    static_assert(is_placeholder_expr<
        pack<Placeholder, pack<>>
    >::value, "");
    static_assert(is_placeholder_expr<
        pack<pack<Placeholder>>
    >::value, "");
};

template <typename = test::placeholder::non_template>
struct with_default_param;

struct test_all
    : test_one<test::placeholder::variadic<>>,
      test_one<test::placeholder::variadic<struct a0>>,
      test_one<test::placeholder::variadic<struct a0, struct a1>>,

      test_one<with_default_param<>>,
      test_one<test::placeholder::non_template>,
      test_one<test::placeholder::unary<struct a0>>,
      test_one<test::placeholder::binary<struct a0, struct a1>>
{ };


int main() { }
