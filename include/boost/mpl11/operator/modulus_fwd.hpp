/*!
 * @file
 * Forward declares `boost::mpl11::modulus`.
 */

#ifndef BOOST_MPL11_OPERATOR_MODULUS_FWD_HPP
#define BOOST_MPL11_OPERATOR_MODULUS_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct modulus; }

    template <typename T1, typename T2, typename ...Tn>
    struct modulus
        : dispatch<tag::modulus, T1, T2, Tn...>
    { };

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup arithmetic_operators
     *
     * Returns `T1 % T2 % ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `modulus<modulus<T1, T2>::type, Tn...>`.
     */
    template <>
    struct modulus<T1, T2, Tn...> { };

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
    struct modulus<IntegralConstant, IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OPERATOR_MODULUS_FWD_HPP
