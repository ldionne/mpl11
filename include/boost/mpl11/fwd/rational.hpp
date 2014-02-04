/*!
 * @file
 * Forward declares the @ref Rational datatype.
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
