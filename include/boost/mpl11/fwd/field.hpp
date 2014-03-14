/*!
 * @file
 * Forward declares the @ref Field typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FWD_FIELD_HPP
#define BOOST_MPL11_FWD_FIELD_HPP

#include <boost/mpl11/fwd/bool.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Field Field
     *
     * `Ring` whose non-zero elements form a `Group` under multiplication.
     *
     *
     * ### Methods
     * `recip` and `quot`
     *
     * ### Minimal complete definition
     * Either `recip` or `quot`.
     *
     *
     * @todo
     * Test the default implementations.
     *
     * @{
     */
    template <typename Left, typename Right = Left, typename = true_>
    struct Field;

    //! Multiplication of `x` by the multiplicative inverse of `y`.
    template <typename x, typename y>
    struct quot;

    //! Multiplicative inverse of `x`.
    template <typename x>
    struct recip;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FIELD_HPP
