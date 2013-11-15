/*!
 * @file
 * Defines `boost::mpl11::detail::is_placeholder_expr`.
 */

#ifndef BOOST_MPL11_DETAIL_IS_PLACEHOLDER_EXPR_HPP
#define BOOST_MPL11_DETAIL_IS_PLACEHOLDER_EXPR_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns whether `E` is a @ref PlaceholderExpression.
     */
    template <typename E>
    struct is_placeholder_expr;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/is_placeholder.hpp>
#include <boost/mpl11/or.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename E>
    struct is_placeholder_expr
        : is_placeholder<E>
    { };

    template <template <typename ...> class F, typename ...T>
    struct is_placeholder_expr<F<T...>>
        : or_<
            is_placeholder<F<T...>>,
            is_placeholder_expr<T>...,
            // or_ requires at least two arguments, hence this dummy
            false_
        >
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_IS_PLACEHOLDER_EXPR_HPP
