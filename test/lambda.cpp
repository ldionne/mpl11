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

// with a normal type
struct some_type;
static_assert(is_same<
    apply<lambda<some_type>>::type,
    some_type
>::value, "");
static_assert(is_same<
    apply<lambda<some_type>, x>::type,
    some_type
>::value, "");
static_assert(is_same<
    apply<lambda<some_type>, x, y>::type,
    some_type
>::value, "");
static_assert(is_same<
    apply<lambda<some_type>, x, y, z>::type,
    some_type
>::value, "");


// with a template specialization
template <typename = struct anything> struct some_template;
static_assert(is_same<
    apply<lambda<some_template<>>>::type,
    some_template<>
>::value, "");
static_assert(is_same<
    apply<lambda<some_template<>>, x>::type,
    some_template<>
>::value, "");
static_assert(is_same<
    apply<lambda<some_template<>>, x, y>::type,
    some_template<>
>::value, "");
static_assert(is_same<
    apply<lambda<some_template<>>, x, y, z>::type,
    some_template<>
>::value, "");


// with a placeholder
template <typename Placeholder>
struct test_straight_placeholder {
    static_assert(is_same<
        typename apply<lambda<Placeholder>>::type,
        typename apply<Placeholder>::type
    >::value, "");
    static_assert(is_same<
        typename apply<lambda<Placeholder>, x>::type,
        typename apply<Placeholder, x>::type
    >::value, "");
    static_assert(is_same<
        typename apply<lambda<Placeholder>, x, y>::type,
        typename apply<Placeholder, x, y>::type
    >::value, "");
    static_assert(is_same<
        typename apply<lambda<Placeholder>, x, y, z>::type,
        typename apply<Placeholder, x, y, z>::type
    >::value, "");
};
struct test_with_a_placeholder
    : test_straight_placeholder<test::placeholder::non_template>,
      test_straight_placeholder<test::placeholder::unary<x>>,
      test_straight_placeholder<test::placeholder::binary<x, y>>,
      test_straight_placeholder<test::placeholder::variadic<>>,
      test_straight_placeholder<test::placeholder::variadic<x>>,
      test_straight_placeholder<test::placeholder::variadic<x, y>>,
      test_straight_placeholder<test::placeholder::variadic<x, y, z>>
{ };


// with various placeholder expressions
template <typename ...> struct f { struct type; };
template <typename P>
struct test_various_placeholder_expr {
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
struct test_placeholder_expr
    : test_various_placeholder_expr<test::placeholder::non_template>,
      test_various_placeholder_expr<test::placeholder::unary<x>>,
      test_various_placeholder_expr<test::placeholder::binary<x, y>>,
      test_various_placeholder_expr<test::placeholder::variadic<>>,
      test_various_placeholder_expr<test::placeholder::variadic<x>>,
      test_various_placeholder_expr<test::placeholder::variadic<x, y>>,
      test_various_placeholder_expr<test::placeholder::variadic<x, y, z>>
{ };


int main() { }
