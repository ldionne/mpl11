/*!
 * @file
 * Contains unit tests for `boost::mpl11::lambda`.
 */

#include <boost/mpl11/functional/lambda.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/functional/apply_wrap.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/operator/not.hpp>


using namespace boost::mpl11;

template <typename ...> struct pack;
struct a0; struct a1; struct a2;

namespace test_variadic_pack_without_placeholders {
    static_assert(equal_to<
        lambda<pack<>>::type,
        pack<>
    >::type::value, "");

    static_assert(equal_to<
        lambda<pack<a0>>::type,
        pack<a0>
    >::type::value, "");

    static_assert(equal_to<
        lambda<pack<a0, a1>>::type,
        pack<a0, a1>
    >::type::value, "");
}

namespace test_lambda_expression_use_cases {
    static_assert(equal_to<
        apply<identity<_1>, int>::type,
        int
    >::type::value, "");

    static_assert(equal_to<
        apply<
            apply_wrap<lambda<identity<_1>>::type, _1>, int
        >::type,
        int
    >::type::value, "");

    static_assert(!apply<
        not_<
            apply_wrap<lambda<identity<_1>>::type, _1>
        >,
        true_
    >::type::value, "");

    static_assert(equal_to<
        apply<_1, int>::type,
        int
    >::type::value, "");
}

// Non placeholder expressions should not be modified.
template <typename NotPlaceholder>
void test_non_placeholder() {
    static_assert(equal_to<
        typename lambda<NotPlaceholder>::type,
        NotPlaceholder
    >::type::value, "");

    static_assert(equal_to<
        typename lambda<pack<NotPlaceholder>>::type,
        pack<NotPlaceholder>
    >::type::value, "");

    static_assert(equal_to<
        typename lambda<pack<pack<NotPlaceholder>>>::type,
        pack<pack<NotPlaceholder>>
    >::type::value, "");
}

struct not_placeholder {
    template <typename ...> struct variadic;
    template <typename> struct unary;
    template <typename, typename> struct binary;
    struct non_template;
};

#define INSTANTIATE_TESTS(TEST, NAMESPACE)                                  \
    TEST<NAMESPACE::variadic<>>();                                          \
    TEST<NAMESPACE::variadic<a0>>();                                        \
    TEST<NAMESPACE::variadic<NAMESPACE::variadic<>>>();                     \
    TEST<NAMESPACE::variadic<NAMESPACE::variadic<a0>>>();                   \
                                                                            \
    TEST<NAMESPACE::unary<a0>>();                                           \
    TEST<NAMESPACE::unary<NAMESPACE::variadic<a0>>>();                      \
                                                                            \
    TEST<NAMESPACE::binary<a0, a1>>();                                      \
    TEST<NAMESPACE::binary<                                                 \
        NAMESPACE::variadic<a0>, NAMESPACE::variadic<a1>                    \
    >>();                                                                   \
                                                                            \
    TEST<NAMESPACE::non_template>();                                        \
/**/


int main() {
    INSTANTIATE_TESTS(test_non_placeholder, not_placeholder)
}
