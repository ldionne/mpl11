/*!
 * @file
 * Forward declares `boost::mpl11::bitxor_`.
 */

#ifndef BOOST_MPL11_FWD_BITXOR_HPP
#define BOOST_MPL11_FWD_BITXOR_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct bitxor_; }

    template <typename T1, typename T2, typename ...Tn>
    struct bitxor_
        : dispatch<tag::bitxor_, T1, T2, Tn...>
    { };

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup bitwise_operators
     *
     * Returns `T1 ^ T2 ^ ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `bitxor_<bitxor_<T1, T2>::type, Tn...>`.
     */
    template <>
    struct bitxor_<T1, T2, Tn...> { };

    /*!
     * @ingroup bitwise_operators
     *
     * Returns the _bitwise xor_ of two
     * @ref IntegralConstant "Integral Constants".
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
     * `identity<integral_c<decltype(T1::value ^ T2::value),
     *                      T1::value ^ T2::value>>`.
     */
    template <>
    struct bitxor_<IntegralConstant, IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BITXOR_HPP
