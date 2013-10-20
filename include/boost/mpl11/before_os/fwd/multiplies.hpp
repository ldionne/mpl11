/*!
 * @file
 * Forward declares `boost::mpl11::multiplies`.
 */

#ifndef BOOST_MPL11_FWD_MULTIPLIES_HPP
#define BOOST_MPL11_FWD_MULTIPLIES_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct multiplies; }

    template <typename T1, typename T2, typename ...Tn>
    struct multiplies
        : dispatch<tag::multiplies, T1, T2, Tn...>
    { };

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup arithmetic_operators
     *
     * Returns `T1 * T2 * ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `multiplies<multiplies<T1, T2>::type, Tn...>`.
     */
    template <>
    struct multiplies<T1, T2, Tn...> { };

    /*!
     * @ingroup arithmetic_operators
     *
     * Returns the multiplication of two
     * @ref IntegralConstant "Integral Constants".
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `identity<integral_c<decltype(T1::value * T2::value),
     *                                    T1::value * T2::value>>`.
     */
    template <>
    struct multiplies<IntegralConstant, IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_MULTIPLIES_HPP
