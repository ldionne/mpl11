/*!
 * @file
 * Forward declares the @ref IntegralDomain typeclass.
 */

#ifndef BOOST_MPL11_FWD_INTEGRAL_DOMAIN_HPP
#define BOOST_MPL11_FWD_INTEGRAL_DOMAIN_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup IntegralDomain Integral Domain
     *
     * Commutative `Ring` without nonzero zero divisors.
     *
     *
     * ### Methods
     * `div` and `mod`
     *
     * ### Minimal complete definition
     * All the methods.
     *
     * @{
     */
    template <typename Left, typename Right = Left>
    struct IntegralDomain;

    template <typename x, typename y>
    struct div;

    template <typename x, typename y>
    struct mod;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTEGRAL_DOMAIN_HPP
