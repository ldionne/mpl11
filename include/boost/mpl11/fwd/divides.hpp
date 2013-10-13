/*!
 * @file
 * Forward declares `boost::mpl11::divides`.
 */

#ifndef BOOST_MPL11_FWD_DIVIDES_HPP
#define BOOST_MPL11_FWD_DIVIDES_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct divides; }

    template <typename T1, typename T2, typename ...Tn>
    struct divides
        : dispatch<tag::divides, T1, T2, Tn...>
    { };

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup arithmetic_operators
     *
     * Returns `T1 / T2 / ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `divides<divides<T1, T2>::type, Tn...>`.
     */
    template <>
    struct divides<T1, T2, Tn...> { };

    /*!
     * @ingroup arithmetic_operators
     *
     * Returns the division of two @ref IntegralConstant "Integral Constants".
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `identity<integral_c<decltype(T1::value / T2::value),
     *                                    T1::value / T2::value>>`.
     *
     *
     * @pre `T2::value != 0`
     */
    template <>
    struct divides<IntegralConstant, IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_DIVIDES_HPP
