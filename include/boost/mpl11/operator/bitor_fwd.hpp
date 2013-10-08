/*!
 * @file
 * Forward declares `boost::mpl11::bitor_`.
 */

#ifndef BOOST_MPL11_OPERATOR_BITOR_FWD_HPP
#define BOOST_MPL11_OPERATOR_BITOR_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct bitor_; }

    template <typename T1, typename T2, typename ...Tn>
    struct bitor_
        : dispatch<tag::bitor_, T1, T2, Tn...>
    { };

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup bitwise_operators
     *
     * Returns `T1 | T2 | ...Tn`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `bitor_<bitor_<T1, T2>::type, Tn...>`.
     */
    template <>
    struct bitor_<T1, T2, Tn...> { };

    /*!
     * @ingroup bitwise_operators
     *
     * Returns the _bitwise or_ of two
     * @ref IntegralConstant "Integral Constants".
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
     * `identity<integral_c<decltype(T1::value | T2::value),
     *                      T1::value | T2::value>>`.
     */
    template <>
    struct bitor_<IntegralConstant, IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OPERATOR_BITOR_FWD_HPP
