/*!
 * @file
 * Forward declares `boost::mpl11::modulo`.
 */

#ifndef BOOST_MPL11_FWD_MODULO_HPP
#define BOOST_MPL11_FWD_MODULO_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup arithmetic_operators
     *
     * Returns `T1 % T2 % ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `modulo<modulo<T1, T2>::type, Tn...>`.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct modulo;

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup arithmetic_operators
     *
     * Returns the modulo of an @ref IntegralConstant by another.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
     * `identity<integral_c<decltype(T1::value % T2::value),
     *                      T1::value % T2::value>>`.
     *
     *
     * @pre `T2::value != 0`
     */
    template <>
    struct modulo<IntegralConstant, IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_MODULO_HPP
