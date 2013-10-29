/*!
 * @file
 * Forward declares `boost::mpl11::negate`.
 */

#ifndef BOOST_MPL11_FWD_NEGATE_HPP
#define BOOST_MPL11_FWD_NEGATE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup arithmetic_operators
     *
     * Returns the additive inverse of an @ref IntegralConstant.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `identity<integral_c<decltype(-T::value), -T::value>>`.
     */
    template <typename Integral>
    struct negate;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NEGATE_HPP
