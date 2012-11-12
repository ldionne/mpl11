/**
 * This file defines the `lambda` metafunction.
 */

#ifndef MPL11_LAMBDA_HPP
#define MPL11_LAMBDA_HPP

#include <mpl11/bind.hpp>
#include <mpl11/eval_if.hpp>
#include <mpl11/identity.hpp>
#include <mpl11/placeholders.hpp>
#include <mpl11/quote.hpp>


namespace mpl11 {

template <typename Expression> struct lambda;

namespace detail {
    template <typename Expression>
    struct parse_lambda {
        using type = Expression;
    };

    template <template <typename ...> class F, typename ...Placeholders>
    struct parse_lambda<F<Placeholders...>> {
        using type = bind<quote<F>, typename lambda<Placeholders>::type...>;
    };
} // end namespace detail

/**
 * Transform a placeholder expression into a metafunction class.
 * If the expression is not a placeholder expression, nothing is done.
 */
template <typename Expression>
struct lambda
    : eval_if<typename is_placeholder_expr<Expression>::type,
        detail::parse_lambda<Expression>,
        identity<Expression>
    >
{ };

} // end namespace mpl11

#endif // !MPL11_LAMBDA_HPP
