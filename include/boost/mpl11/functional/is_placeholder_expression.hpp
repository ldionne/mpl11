/*!
 * @file
 * Defines `boost::mpl11::is_placeholder_expression`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_IS_PLACEHOLDER_EXPRESSION_HPP
#define BOOST_MPL11_FUNCTIONAL_IS_PLACEHOLDER_EXPRESSION_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/functional/is_placeholder.hpp>
#include <boost/mpl11/operator/or.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup functional
     *
     * Returns whether `E` is a @ref PlaceholderExpression.
     */
    template <typename E>
    struct is_placeholder_expression
        : is_placeholder<E>
    { };

    template <template <typename ...> class F, typename ...T>
    struct is_placeholder_expression<F<T...>>
        : or_<
            is_placeholder<F<T...>>,
            is_placeholder_expression<T>...,
            // or_ requires at least two arguments, hence this dummy
            false_
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_IS_PLACEHOLDER_EXPRESSION_HPP
