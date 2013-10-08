/*!
 * @file
 * Forward declares `boost::mpl11::minus`.
 */

#ifndef BOOST_MPL11_OPERATOR_MINUS_FWD_HPP
#define BOOST_MPL11_OPERATOR_MINUS_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct minus; }

    template <typename T1, typename T2, typename ...Tn>
    struct minus
        : dispatch<tag::minus, T1, T2, Tn...>
    { };

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup arithmetic_operators
     *
     * Returns `T1 - T2 - ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `minus<minus<T1, T2>::type, Tn...>`.
     */
    template <>
    struct minus<T1, T2, Tn...> { };

    /*!
     * @ingroup arithmetic_operators
     *
     * Returns the subtraction of two
     * @ref IntegralConstant "Integral Constants".
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `identity<integral_c<decltype(T1::value - T2::value),
     *                                    T1::value - T2::value>>`.
     */
    template <>
    struct minus<IntegralConstant, IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OPERATOR_MINUS_FWD_HPP
