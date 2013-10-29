/*!
 * @file
 * Contains unit tests for `boost::mpl11::apply_wrap`.
 */

#include <boost/mpl11/apply_wrap.hpp>

#include "metafunction_classes.hpp"
#include <boost/mpl11/detail/has_type.hpp>
#include <boost/mpl11/equal_to.hpp>


using namespace boost::mpl11;
using detail::has_type;

namespace does_what_it_should_do_when_everything_is_valid {
    using variadic = with_nested_type::variadic;
    using non_template = with_nested_type::non_template;
    using unary = with_nested_type::unary;
    using binary = with_nested_type::binary;

    static_assert(equal_to<
        apply_wrap<variadic>::type,
        variadic::apply<>::type
    >::type::value, "");

    static_assert(equal_to<
        apply_wrap<variadic, struct a0>::type,
        variadic::apply<struct a0>::type
    >::type::value, "");

    static_assert(equal_to<
        apply_wrap<variadic, struct a0, struct a1>::type,
        variadic::apply<struct a0, struct a1>::type
    >::type::value, "");

    static_assert(equal_to<
        apply_wrap<unary, struct a0>::type,
        unary::apply<struct a0>::type
    >::type::value, "");

    static_assert(equal_to<
        apply_wrap<binary, struct a0, struct a1>::type,
        binary::apply<struct a0, struct a1>::type
    >::type::value, "");

    static_assert(equal_to<
        apply_wrap<non_template>::type,
        non_template::apply::type
    >::type::value, "");
}

template <typename NS>
void SFINAE_friendly_when_wrong_number_of_args() {
    static_assert(!has_type<
        apply_wrap<typename NS::non_template, struct a0>
    >::value, "");

    static_assert(!has_type<
        apply_wrap<typename NS::unary>
    >::value, "");

    static_assert(!has_type<
        apply_wrap<typename NS::unary, struct a0, struct a1>
    >::value, "");

    static_assert(!has_type<
        apply_wrap<typename NS::binary>
    >::value, "");

    static_assert(!has_type<
        apply_wrap<typename NS::binary, struct a0>
    >::value, "");

    static_assert(!has_type<
        apply_wrap<typename NS::binary, struct a0, struct a1, struct a2>
    >::value, "");
}

template <typename NS>
void SFINAE_friendly_when_no_nested_type() {
    static_assert(!has_type<
        apply_wrap<typename NS::variadic>
    >::value, "");

    static_assert(!has_type<
        apply_wrap<typename NS::variadic, struct a0>
    >::value, "");

    static_assert(!has_type<
        apply_wrap<typename NS::variadic, struct a0, struct a1>
    >::value, "");

    static_assert(!has_type<
        apply_wrap<typename NS::non_template>
    >::value, "");

    static_assert(!has_type<
        apply_wrap<typename NS::non_template, struct a0>
    >::value, "");

    static_assert(!has_type<
        apply_wrap<typename NS::unary, struct a0>
    >::value, "");

    static_assert(!has_type<
        apply_wrap<typename NS::binary, struct a0, struct a1>
    >::value, "");
}


int main() {
    SFINAE_friendly_when_no_nested_type<without_nested_type>();
    SFINAE_friendly_when_no_nested_type<with_incomplete_apply>();

    SFINAE_friendly_when_wrong_number_of_args<with_nested_type>();
    SFINAE_friendly_when_wrong_number_of_args<without_nested_type>();
    SFINAE_friendly_when_wrong_number_of_args<with_incomplete_apply>();
}
