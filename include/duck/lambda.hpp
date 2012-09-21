/**
 * This file defines the lambda metafunction.
 */

#ifndef DUCK_LAMBDA_HPP
#define DUCK_LAMBDA_HPP

#include <duck/any_of.hpp>
#include <duck/apply.hpp>
#include <duck/bind.hpp>
#include <duck/identity.hpp>
#include <duck/if.hpp>
#include <duck/placeholders.hpp>
#include <duck/push_front.hpp>
#include <duck/quote.hpp>
#include <duck/transform.hpp>

#include <cstddef>
#include <type_traits>


namespace duck {

namespace detail {

// A normal type is not a placeholder expression.
template <typename T>
struct lambda_impl {
    using type = T;
    using is_lambda_expr = std::false_type;
};

// A placeholder is a placeholder expression.
template <std::size_t i>
struct lambda_impl<placeholder<i>> {
    using type = placeholder<i>;
    using is_lambda_expr = std::true_type;
};

// A template template parameter might be a placeholder expression.
// We determine whether it is one and return accordingly.
template <template <typename ...> class F, typename ...Placeholders>
struct lambda_impl<F<Placeholders...>> {
private:
    //Create a recursive parser. We need to use identity because we want to
    //put lambda_impl<T> instead of lambda_impl<T>::type in the parsed result.
    template <typename T>
    struct parse : identity< ::duck::detail::lambda_impl<T>> { };

    // Use the parser on the placeholders. After this,
    // ``parsed'' is duck::pack<lambda_impl<T>, ...>.
    using parsed = typename transform<quote<parse>, Placeholders...>::type;

    template <typename T>
    struct get_is_lambda_expr { using type = typename T::is_lambda_expr; };

    template <typename T>
    struct get_type { using type = typename T::type; };

    template <typename ...ParsedPlaceholders>
    struct any_is_lambda_expr
        : any_of<quote<get_is_lambda_expr>, ParsedPlaceholders...> { };

    template <typename ...ParsedPlaceholders>
    struct as_lambda_exprs_var
        : transform<quote<get_type>, ParsedPlaceholders...> { };

    template <typename ParsedPack>
    struct as_lambda_exprs
        : apply_pack<quote<as_lambda_exprs_var>, ParsedPack> { };

    template <typename F_, typename ParsedPack>
    struct prepare_pack
        : push_front<F_, typename as_lambda_exprs<ParsedPack>::type> { };

public:
    // This expression is a lambda expression if any one of
    // the placeholders was a lambda expression.
    using is_lambda_expr = typename
        apply_pack<
            quote<any_is_lambda_expr>,
            parsed
        >::type;

    // If this is a lambda expression, we return the corresponding bind
    // expression. Otherwise, we return the original expression unchanged.
    using type = typename
        if_<is_lambda_expr,
            bind_pack<typename prepare_pack<quote<F>, parsed>::type>,
            F<Placeholders...>
        >::type;
};

} // end namespace detail

/**
 * Transform a placeholder expression into a metafunction class.
 * If the expression is not a placeholder expression, nothing is done.
 */
template <typename Expression>
struct lambda {
    using type = typename detail::lambda_impl<Expression>::type;
};

} // end namespace duck

#endif // !DUCK_LAMBDA_HPP
