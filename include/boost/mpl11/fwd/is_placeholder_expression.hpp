/*!
 * @file
 * Forward declares `boost::mpl11::is_placeholder_expression`.
 */

#ifndef BOOST_MPL11_FWD_IS_PLACEHOLDER_EXPRESSION_HPP
#define BOOST_MPL11_FWD_IS_PLACEHOLDER_EXPRESSION_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup functional
     *
     * Returns whether `E` is a @ref PlaceholderExpression.
     */
    template <typename E>
    struct is_placeholder_expression;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IS_PLACEHOLDER_EXPRESSION_HPP
