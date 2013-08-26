/*!
 * @file
 * This file contains unit tests for `boost::mpl11::lambda`.
 */

#include <boost/mpl11/lambda.hpp>

#include "placeholders.hpp"
#include <boost/mpl11/as_placeholder.hpp>
#include <boost/mpl11/bind.hpp>
#include <boost/mpl11/is_placeholder.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/quote.hpp>


using namespace boost::mpl11;

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

template <typename ...Expressions>
void test_apply_wrap_equivalence() {
    static_assert(is_same<
        typename apply_wrap<Expressions>::type...
    >::value, "");

    static_assert(is_same<
        typename apply_wrap<Expressions, a0>::type...
    >::value, "");

    static_assert(is_same<
        typename apply_wrap<Expressions, a0, a1>::type...
    >::value, "");
}

// Placeholder expressions should be replaced, but placeholders
// (templates or otherwise) should not.
template <typename Placeholder>
void test_placeholder() {
    static_assert(is_same<
        typename lambda<Placeholder>::type,
        Placeholder
    >::value, "");

    test_apply_wrap_equivalence<
        typename lambda<pack<Placeholder>>::type,
        bind<quote<pack>, Placeholder>
    >();

    test_apply_wrap_equivalence<
        typename lambda<pack<Placeholder, a0>>::type,
        bind<quote<pack>, Placeholder, a0>
    >();

    test_apply_wrap_equivalence<
        typename lambda<pack<a0, Placeholder>>::type,
        bind<quote<pack>, a0, Placeholder>
    >();

    test_apply_wrap_equivalence<
        typename lambda<
            pack<
                Placeholder,
                typename lambda<pack<Placeholder>>::type
            >
        >::type,
        typename lambda<
            pack<
                Placeholder,
                as_placeholder<bind<quote<pack>, Placeholder>>
            >
        >::type,
        bind<
            quote<pack>,
            Placeholder,
            as_placeholder<bind<quote<pack>, Placeholder>>
        >
    >();
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
    INSTANTIATE_TESTS(test_placeholder, placeholder)
    INSTANTIATE_TESTS(test_non_placeholder, not_placeholder)
}
