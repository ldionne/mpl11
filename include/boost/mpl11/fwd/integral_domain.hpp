/*!
 * @file
 * Forward declares the @ref IntegralDomain typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FWD_INTEGRAL_DOMAIN_HPP
#define BOOST_MPL11_FWD_INTEGRAL_DOMAIN_HPP

#include <boost/mpl11/fwd/bool.hpp>


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
    template <typename Left, typename Right = Left, typename = true_>
    struct IntegralDomain;

    //! Integer division of `x` by `y`.
    template <typename x, typename y>
    struct div;

    //! Remainder of the integer division of `x` by `y`.
    template <typename x, typename y>
    struct mod;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTEGRAL_DOMAIN_HPP
