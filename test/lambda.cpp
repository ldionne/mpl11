/*!
 * @file
 * Contains unit tests for `boost::mpl11::lambda`.
 */

#include <boost/mpl11/lambda.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>

#include "detail/placeholders.hpp"


using namespace boost::mpl11;
using detail::is_same;

struct x; struct y; struct z;
struct some_type;
template <typename = struct anything> struct some_template;
template <typename ...> struct f { struct type; };

template <typename Body>
struct test_lambda {
    template <typename ...Args>
    struct with {
        template <typename Result>
        struct equals {
            static_assert(is_same<
                apply_t<lambda<Body>, Args...>, Result
            >::value, "");
        };
    };
};


struct test_with_a_normal_type :
    test_lambda<some_type>::with<>::equals<some_type>,
    test_lambda<some_type>::with<x>::equals<some_type>,
    test_lambda<some_type>::with<x, y>::equals<some_type>,
    test_lambda<some_type>::with<x, y, z>::equals<some_type>
{ };


struct test_with_a_template_specialization :
    test_lambda<some_template<>>::with<>::equals<some_template<>>,
    test_lambda<some_template<>>::with<x>::equals<some_template<>>,
    test_lambda<some_template<>>::with<x, y>::equals<some_template<>>,
    test_lambda<some_template<>>::with<x, y, z>::equals<some_template<>>
{ };


template <typename Placeholder>
struct test_with_a_placeholder_impl {
    static_assert(is_same<
        apply_t<lambda<Placeholder>>, apply_t<Placeholder>
    >::value, "");
    static_assert(is_same<
        apply_t<lambda<Placeholder>, x>, apply_t<Placeholder, x>
    >::value, "");
    static_assert(is_same<
        apply_t<lambda<Placeholder>, x, y>, apply_t<Placeholder, x, y>
    >::value, "");
    static_assert(is_same<
        apply_t<lambda<Placeholder>, x, y, z>, apply_t<Placeholder, x, y, z>
    >::value, "");
};
struct test_with_a_placeholder :
    test_with_a_placeholder_impl<test::placeholder::non_template>,
    test_with_a_placeholder_impl<test::placeholder::unary<x>>,
    test_with_a_placeholder_impl<test::placeholder::binary<x, y>>,
    test_with_a_placeholder_impl<test::placeholder::variadic<>>,
    test_with_a_placeholder_impl<test::placeholder::variadic<x>>,
    test_with_a_placeholder_impl<test::placeholder::variadic<x, y>>,
    test_with_a_placeholder_impl<test::placeholder::variadic<x, y, z>>
{ };


template <typename P>
struct test_various_lambda_expr_impl {
    template <typename ...Args>
    struct with_args {
        static_assert(is_same<
            typename apply<lambda<f<P>>, Args...>::type,
            typename f<
                typename apply<P, Args...>::type
            >::type
        >::value, "");

        static_assert(is_same<
            typename apply<lambda<f<P, P>>, Args...>::type,
            typename f<
                typename apply<P, Args...>::type,
                typename apply<P, Args...>::type
            >::type
        >::value, "");

        static_assert(is_same<
            typename apply<lambda<f<f<P>>>, Args...>::type,
            typename f<
                typename f<
                    typename apply<P, Args...>::type
                >::type
            >::type
        >::value, "");

        static_assert(is_same<
            typename apply<lambda<f<f<P>, P>>, Args...>::type,
            typename f<
                typename f<
                    typename apply<P, Args...>::type
                >::type,
                typename apply<P, Args...>::type
            >::type
        >::value, "");

        static_assert(is_same<
            typename apply<lambda<f<f<P>, some_type>>, Args...>::type,
            typename f<
                typename f<
                    typename apply<P, Args...>::type
                >::type,
                some_type
            >::type
        >::value, "");

        static_assert(is_same<
            typename apply<lambda<f<f<P>, some_template<>>>, Args...>::type,
            typename f<
                typename f<
                    typename apply<P, Args...>::type
                >::type,
                some_template<>
            >::type
        >::value, "");

        // Test with nested lambdas
        static_assert(is_same<
            typename apply<lambda<lambda<some_type>>, Args...>::type,
            lambda<some_type>
        >::value, "");
        static_assert(is_same<
            typename apply<lambda<lambda<some_template<>>>, Args...>::type,
            lambda<some_template<>>
        >::value, "");
        static_assert(is_same<
            typename apply<lambda<lambda<P>>, Args...>::type,
            lambda<P>
        >::value, "");
        static_assert(is_same<
            typename apply<lambda<lambda<f<P>>>, Args...>::type,
            lambda<f<P>>
        >::value, "");
        static_assert(is_same<
            typename apply<
                lambda<
                    f<
                        apply<lambda<struct anything>, P>
                    >
                >, Args...
            >::type,
            typename f<
                typename apply<
                    lambda<struct anything>,
                    typename apply<P, Args...>::type
                >::type
            >::type
        >::value, "");

        static_assert(is_same<
            typename apply<
                lambda<
                    f<
                        apply<lambda<P>, P>
                    >
                >, Args...
            >::type,
            typename f<
                typename apply<
                    lambda<P>,
                    typename apply<P, Args...>::type
                >::type
            >::type
        >::value, "");
    };

    static_assert(
        sizeof(with_args<>) +
        sizeof(with_args<x>) +
        sizeof(with_args<x, y>) +
        sizeof(with_args<x, y, z>) +
        sizeof(with_args<x, y, z, some_template<>>)
    , "");
};
struct test_various_lambda_expr :
    test_various_lambda_expr_impl<test::placeholder::non_template>,
    test_various_lambda_expr_impl<test::placeholder::unary<x>>,
    test_various_lambda_expr_impl<test::placeholder::binary<x, y>>,
    test_various_lambda_expr_impl<test::placeholder::variadic<>>,
    test_various_lambda_expr_impl<test::placeholder::variadic<x>>,
    test_various_lambda_expr_impl<test::placeholder::variadic<x, y>>,
    test_various_lambda_expr_impl<test::placeholder::variadic<x, y, z>>
{ };


int main() { }
