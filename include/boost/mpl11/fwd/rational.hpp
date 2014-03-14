/*!
 * @file
 * Forward declares the @ref Rational datatype.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FWD_RATIONAL_HPP
#define BOOST_MPL11_FWD_RATIONAL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     * @defgroup Rational Rational
     *
     * Exact rational number represented as a ratio of two integers.
     *
     *
     *
     * ### Instance of
     * `Comparable`, `Orderable`, `Monoid`, `Group`, `Ring` and `Field`.
     *
     * @todo
     * - Write unit tests for the provided instances.
     * - Consider checking for overflows and reducing the fraction after
     *   doing computations.
     * - Consider instantiating `IntegralDomain`.
     *
     * @{
     */
    struct Rational;

    template <typename T, T numerator, T denominator = (T)1>
    struct rational_c;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_RATIONAL_HPP
