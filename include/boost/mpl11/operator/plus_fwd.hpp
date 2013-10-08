/*!
 * @file
 * Forward declares `boost::mpl11::plus`.
 */

#ifndef BOOST_MPL11_OPERATOR_PLUS_FWD_HPP
#define BOOST_MPL11_OPERATOR_PLUS_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct plus; }

    template <typename T1, typename T2, typename ...Tn>
    struct plus
        : dispatch<tag::plus, T1, T2, Tn...>
    { };

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup arithmetic_operators
     *
     * Returns `T1 + T2 + ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `plus<plus<T1, T2>::type, Tn...>`.
     */
    template <>
    struct plus<T1, T2, Tn...> { };

    /*!
     * @ingroup arithmetic_operators
     *
     * Returns the sum of two @ref IntegralConstant "Integral Constants".
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `identity<integral_c<decltype(T1::value + T2::value),
     *                                    T1::value + T2::value>>`.
     */
    template <>
    struct plus<IntegralConstant, IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OPERATOR_PLUS_FWD_HPP
