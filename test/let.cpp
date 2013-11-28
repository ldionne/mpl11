/*!
 * @file
 * Contains unit tests for `boost::mpl11::let`.
 */

#include <boost/mpl11/let.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/dependent_on.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/fwd/is_placeholder.hpp>
#include <boost/mpl11/integral_c.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <int> struct k;
template <int> struct v;
struct x; struct y; struct z;
struct a_type;
template <typename = a_type> struct a_template;
template <typename ...> struct f { struct type; };
template <typename X> struct fail {
    static_assert(detail::dependent_on<X>::template value<bool, false>(), "");
};

template <typename P>
struct generic_test {
    template <typename ...Args>
    struct with_args {
        //////////////////////////////////////////////////////////////////////
        // Make sure nested let-expressions are not evaluated.
        // The test works in the following way:
        // We create a let-expression A and we nest another let-expression B
        // inside of it. The body of B is such that if B is evaluated, a
        // static assertion will be triggered.
        //////////////////////////////////////////////////////////////////////
        using TriggerTest = apply_t<let<>(let<>(fail<P>)), Args...>;

        //////////////////////////////////////////////////////////////////////
        // Make sure a lonely regular type or a template specialization
        // is left as-is.
        //////////////////////////////////////////////////////////////////////
        static_assert(is_same<
            apply_t<let<>(a_type), Args...>,
            a_type
        >::value, "");

        static_assert(is_same<
            apply_t<let<>(a_template<>), Args...>,
            a_template<>
        >::value, "");

        //////////////////////////////////////////////////////////////////////
        // Make sure a lonely placeholder is invoked with the arguments
        // passed to the let-expression.
        //////////////////////////////////////////////////////////////////////
        static_assert(is_same<
            apply_t<let<>(P), Args...>,
            apply_t<P, Args...>
        >::value, "");

        //////////////////////////////////////////////////////////////////////
        // Make sure a nested placeholder is invoked with the arguments
        // passed to the enclosing let-expression, and that the expression
        // containing it is evaluated.
        //////////////////////////////////////////////////////////////////////

        // 1 level of nesting
        static_assert(is_same<
            apply_t<let<>(f<P>), Args...>,
            typename f<apply_t<P, Args...>>::type
        >::value, "");

        static_assert(is_same<
            apply_t<let<>(f<P, P>), Args...>,
            typename f<apply_t<P, Args...>, apply_t<P, Args...>>::type
        >::value, "");

        // 2 levels of nesting
        static_assert(is_same<
            apply_t<let<>(f<f<P>>), Args...>,
            typename f<typename f<apply_t<P, Args...>>::type>::type
        >::value, "");

        // mixed levels of nesting
        template <typename T, typename R>
        using mixed_levels = is_same<
            apply_t<let<>(f<f<P>, T>), Args...>,
            typename f<typename f<apply_t<P, Args...>>::type, R>::type
        >;
        static_assert(mixed_levels<P, apply_t<P, Args...>>::value, "");
        static_assert(mixed_levels<a_type, a_type>::value, "");
        static_assert(mixed_levels<a_template<>, a_template<>>::value, "");


        //////////////////////////////////////////////////////////////////////
        // Make sure a lonely local variable is replaced.
        //////////////////////////////////////////////////////////////////////
        static_assert(is_same<
            apply_t<
                let<local<k<0>, v<0>>>(k<0>),
                Args...
            >,
            v<0>
        >::value, "");

        //////////////////////////////////////////////////////////////////////
        // Make sure a nested local variable is replaced, and the
        // expression containing it is evaluated.
        //////////////////////////////////////////////////////////////////////
        static_assert(is_same<
            apply_t<
                let<local<k<0>, v<0>>>(f<k<0>>),
                Args...
            >,
            typename f<v<0>>::type
        >::value, "");

        //////////////////////////////////////////////////////////////////////
        // Make sure outer local variables are in the scope of
        // nested let-expressions.
        //////////////////////////////////////////////////////////////////////
        static_assert(is_same<
            apply_t<
                let<local<k<0>, v<0>>>(
                    // We use an implicit local variable just to force
                    // the evaluation of the nested apply.
                    apply<let<>(k<0>), P>
                ),
                Args...
            >,
            v<0>
        >::value, "");

        //////////////////////////////////////////////////////////////////////
        // Make sure outer local variables are hidden by local variables
        // with the same name in nested let-expressions.
        //////////////////////////////////////////////////////////////////////
        static_assert(is_same<
            apply_t<
                let<local<k<0>, v<0>>>(
                    // We use an implicit local variable just to force
                    // the evaluation of the nested apply.
                    apply<let<local<k<0>, v<1>>>(k<0>), P>
                ),
                Args...
            >,
            v<1>
        >::value, "");
    };

    struct test_with_args :
        with_args<>,
        with_args<x>,
        with_args<x, y>,
        with_args<x, y, z>,
        with_args<x, y, z, a_template<>>
    { };

    static_assert(sizeof(test_with_args), "");
};

template <typename ...>
struct variadic {
    template <typename ...>
    struct apply { struct type; };
};

template <typename>
struct unary {
    template <typename ...>
    struct apply { struct type; };
};

template <typename, typename>
struct binary {
    template <typename ...>
    struct apply { struct type; };
};

struct non_template {
    template <typename ...>
    struct apply { struct type; };
};

namespace boost { namespace mpl11 {
    template <typename ...T>
    struct is_placeholder<variadic<T...>> : true_ { };

    template <typename T>
    struct is_placeholder<unary<T>> : true_ { };

    template <typename T, typename U>
    struct is_placeholder<binary<T, U>> : true_ { };

    template <>
    struct is_placeholder<non_template> : true_ { };
}} // end namespace boost::mpl11

struct test_with_various_placeholders :
    generic_test<non_template>,
    generic_test<unary<x>>,
    generic_test<binary<x, y>>,
    generic_test<variadic<>>,
    generic_test<variadic<x>>,
    generic_test<variadic<x, y>>,
    generic_test<variadic<x, y, z>>
{ };


int main() { }
