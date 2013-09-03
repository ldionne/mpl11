/*!
 * @file
 * Contains unit tests for `boost::mpl11::lambda`.
 */

#include <boost/mpl11/lambda.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/not.hpp>
#include <boost/mpl11/lambda.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename ...> struct pack;
struct a0; struct a1; struct a2;

namespace test_variadic_pack_without_placeholders {
    static_assert(is_same<
        lambda<pack<>>::type,
        pack<>
    >::value, "");

    static_assert(is_same<
        lambda<pack<a0>>::type,
        pack<a0>
    >::value, "");

    static_assert(is_same<
        lambda<pack<a0, a1>>::type,
        pack<a0, a1>
    >::value, "");
}

namespace test_lambda_expression_use_cases {
    static_assert(is_same<
        apply<identity<_1>, int>::type,
        int
    >::value, "");

    static_assert(is_same<
        apply<
            apply_wrap<lambda<identity<_1>>::type, _1>, int
        >::type,
        int
    >::value, "");

    static_assert(!apply<
        intrinsic::not_<
            apply_wrap<lambda<identity<_1>>::type, _1>
        >,
        true_
    >::type::value, "");

    static_assert(is_same<
        apply<_1, int>::type,
        int
    >::value, "");
}

// Non placeholder expressions should not be modified.
template <typename NotPlaceholder>
void test_non_placeholder() {
    static_assert(is_same<
        typename lambda<NotPlaceholder>::type,
        NotPlaceholder
    >::value, "");

    static_assert(is_same<
        typename lambda<pack<NotPlaceholder>>::type,
        pack<NotPlaceholder>
    >::value, "");

    static_assert(is_same<
        typename lambda<pack<pack<NotPlaceholder>>>::type,
        pack<pack<NotPlaceholder>>
    >::value, "");
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
