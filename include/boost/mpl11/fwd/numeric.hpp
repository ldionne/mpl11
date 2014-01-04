/*!
 * @file
 * Forward declares `boost::mpl11::Numeric`.
 */

#ifndef BOOST_MPL11_FWD_NUMERIC_HPP
#define BOOST_MPL11_FWD_NUMERIC_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    template <typename, typename> struct plus_impl;
    template <typename, typename> struct minus_impl;
    template <typename, typename> struct times_impl;
    template <typename>           struct negate_impl;
    template <typename>           struct abs_impl;
    template <typename>           struct sign_impl;

    /*!
     * @ingroup typeclasses
     * @defgroup Numeric Numeric
     *
     * Typeclass providing basic numeric capabilities.
     *
     *
     * ### Methods
     * `plus`, `minus`, `times`, `negate`, `abs` and `sign`.
     *
     * For any `Numeric` `x`, `x` should be equivalent to
     * `times_t<abs_t<x>, sign_t<x>>`.
     *
     * ### Minimal complete definition
     * All the methods.
     *
     * @{
     */
    template <typename TagL, typename TagR = TagL>
    struct Numeric;

    //! Returns the sum of the given objects (`M + N`).
    template <typename M, typename N>
    BOOST_MPL11_DOXYGEN_ALIAS(plus, plus_impl<M, N>);

    template <typename M, typename N>
    using plus_t = typename plus<M, N>::type;


    //! Returns the subtraction of the given objects (`M - N`).
    template <typename M, typename N>
    BOOST_MPL11_DOXYGEN_ALIAS(minus, minus_impl<M, N>);

    template <typename M, typename N>
    using minus_t = typename minus<M, N>::type;


    //! Returns the product of the given objects (`M * N`).
    template <typename M, typename N>
    BOOST_MPL11_DOXYGEN_ALIAS(times, times_impl<M, N>);

    template <typename M, typename N>
    using times_t = typename times<M, N>::type;


    //! Returns the unary negation of the given object (`-N`).
    template <typename N>
    BOOST_MPL11_DOXYGEN_ALIAS(negate, negate_impl<N>);

    template <typename N>
    using negate_t = typename negate<N>::type;


    //! Returns the absolute value of the given object.
    template <typename N>
    BOOST_MPL11_DOXYGEN_ALIAS(abs, abs_impl<N>);

    template <typename N>
    using abs_t = typename abs<N>::type;


    /*!
     * Returns the sign of the given object.
     *
     * For real numbers, the sign is either `-1` (negative), `0` (zero) or
     * `1` (positive).
     */
    template <typename N>
    BOOST_MPL11_DOXYGEN_ALIAS(sign, sign_impl<N>);

    template <typename N>
    using sign_t = typename sign<N>::type;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NUMERIC_HPP
