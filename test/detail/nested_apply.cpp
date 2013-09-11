/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::nested_apply`.
 */

#include <boost/mpl11/detail/nested_apply.hpp>

#include "../functional/metafunction_classes.hpp"
#include <boost/mpl11/detail/has_type.hpp>
#include <boost/mpl11/detail/is_same.hpp>


using boost::mpl11::detail::has_type;
using boost::mpl11::detail::nested_apply;
using boost::mpl11::detail::is_same;

template <typename NS>
void test() {
    // Non template apply
    static_assert(is_same<
        typename nested_apply<typename NS::non_template>::type,
        typename NS::non_template::apply
    >::value, "");

    static_assert(!has_type<
        nested_apply<typename NS::non_template, struct a0>
    >::value, "");

    static_assert(!has_type<
        nested_apply<typename NS::non_template, struct a0, struct a1>
    >::value, "");


    // Unary template apply
    static_assert(is_same<
        typename nested_apply<typename NS::unary, struct a0>::type,
        typename NS::unary::template apply<struct a0>
    >::value, "");

    static_assert(!has_type<
        nested_apply<typename NS::unary>
    >::value, "");

    static_assert(!has_type<
        nested_apply<typename NS::unary, struct a0, struct a1>
    >::value, "");


    // Binary template apply
    static_assert(is_same<
        typename nested_apply<typename NS::binary, struct a0, struct a1>::type,
        typename NS::binary::template apply<struct a0, struct a1>
    >::value, "");

    static_assert(!has_type<
        nested_apply<typename NS::binary>
    >::value, "");

    static_assert(!has_type<
        nested_apply<typename NS::binary, struct a0>
    >::value, "");

    static_assert(!has_type<
        nested_apply<typename NS::binary, struct a0, struct a1, struct a2>
    >::value, "");


    // Variadic template apply
    static_assert(is_same<
        typename nested_apply<typename NS::variadic>::type,
        typename NS::variadic::template apply<>
    >::value, "");

    static_assert(is_same<
        typename nested_apply<typename NS::variadic, struct a0>::type,
        typename NS::variadic::template apply<struct a0>
    >::value, "");

    static_assert(is_same<
        typename nested_apply<typename NS::variadic, struct a0, struct a1>::type,
        typename NS::variadic::template apply<struct a0, struct a1>
    >::value, "");
}


int main() {
    test<with_nested_type>();
    test<without_nested_type>();
    test<with_incomplete_apply>();
}
