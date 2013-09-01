/*!
 * @file
 * Defines `boost::mpl11::lambda`.
 */

#ifndef BOOST_MPL11_LAMBDA_HPP
#define BOOST_MPL11_LAMBDA_HPP

#include <boost/mpl11/as_placeholder.hpp>
#include <boost/mpl11/bind.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/not.hpp>
#include <boost/mpl11/intrinsic/or.hpp>
#include <boost/mpl11/is_placeholder.hpp>
#include <boost/mpl11/is_placeholder_expression.hpp>
#include <boost/mpl11/quote.hpp>


namespace boost { namespace mpl11 {
/*!
 * Transforms a `LambdaExpression` into its corresponding `MetafunctionClass`.
 *
 * If `T` is a `Placeholder` or if it is not a `PlaceholderExpression`,
 * returns `T` unchanged. Otherwise, let `T` be a `PlaceholderExpression`
 * in a general form `F<A1, ...An>`, where `F` is a class template and
 * `A1, ...An` are arbitrary types. `lambda<F<A1, ...An>>::type` is the same
 * as `as_placeholder<bind<quote<F>, lambda<A1>::type, ...lambda<An>::type>>`.
 *
 * @warning
 * Differences from the original MPL:
 * - `Placeholder`s are left unchanged.
 * - `PlaceholderExpression`s are replaced by something different;
 *   `mpl::protect` is not used anymore.
 */
template <typename T>
struct lambda
    : identity<T>
{ };

namespace lambda_detail {
    template <template <typename ...> class F, typename ...T>
    struct lazy_bind_quote
        : identity<
            as_placeholder<
                bind<quote<F>, typename lambda<T>::type...>
            >
        >
    { };

    template <typename ...E>
    struct none_is_placeholder_expression
        : intrinsic::not_<intrinsic::or_<is_placeholder_expression<E>...>>
    { };

    template <typename E>
    struct none_is_placeholder_expression<E>
        : intrinsic::not_<is_placeholder_expression<E>>
    { };

    template <>
    struct none_is_placeholder_expression<>
        : true_
    { };
} // end namespace lambda_detail

template <template <typename ...> class F, typename ...T>
struct lambda<F<T...>>
    : if_<
        intrinsic::or_<
            is_placeholder<F<T...>>,
            lambda_detail::none_is_placeholder_expression<T...>
        >,
        identity<F<T...>>,
        lambda_detail::lazy_bind_quote<F, T...>
    >::type
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LAMBDA_HPP
