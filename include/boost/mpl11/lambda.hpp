/*!
 * @file
 * This file defines `boost::mpl11::lambda`.
 */

#ifndef BOOST_MPL11_LAMBDA_HPP
#define BOOST_MPL11_LAMBDA_HPP

#include <mpl11/bind.hpp>
#include <mpl11/eval_if.hpp>
#include <mpl11/identity.hpp>
#include <mpl11/placeholder.hpp>
#include <mpl11/quote.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename Expression> struct lambda;

namespace lambda_detail {
    template <typename Expression>
    struct parse_lambda {
        using type = Expression;
    };

    template <typename ...Placeholders>
    struct parse_lambda<bind<Placeholders...>> {
        using type = bind<Placeholders...>;
    };

    template <template <typename ...> class F, typename ...Placeholders>
    struct parse_lambda<F<Placeholders...>> {
        using type = bind<quote<F>, typename lambda<Placeholders>::type...>;
    };
} // end namespace lambda_detail

template <typename Expression>
struct lambda
    : eval_if<typename is_placeholder_expr<Expression>::type,
        lambda_detail::parse_lambda<Expression>,
        identity<Expression>
    >
{ };
}}}

#endif // !BOOST_MPL11_LAMBDA_HPP
