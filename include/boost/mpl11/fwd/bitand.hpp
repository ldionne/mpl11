/*!
 * @file
 * Forward declares `boost::mpl11::bitand_`.
 */

#ifndef BOOST_MPL11_FWD_BITAND_HPP
#define BOOST_MPL11_FWD_BITAND_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup bitwise_operators
     *
     * Returns `T1 & T2 & ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `bitand_<bitand_<T1, T2>::type, Tn...>`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct bitand_;

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup bitwise_operators
     *
     * @todo move to right concept
     * Returns the _bitwise and_ of two
     * @ref IntegralConstant "Integral Constants".
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
     * `identity<integral_c<decltype(T1::value & T2::value),
     *                      T1::value & T2::value>>`.
     */
    template <>
    struct bitand_<IntegralConstant, IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BITAND_HPP
