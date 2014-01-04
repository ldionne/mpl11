/*!
 * @file
 * Forward declares `boost::mpl11::Integral`.
 */

#ifndef BOOST_MPL11_FWD_INTEGRAL_HPP
#define BOOST_MPL11_FWD_INTEGRAL_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    template <typename, typename> struct quot_impl;
    template <typename, typename> struct rem_impl;

    /*!
     * @ingroup typeclasses
     * @defgroup Integral Integral
     *
     * Integral numbers supporting integer division.
     *
     *
     * ### Refines
     * `Orderable`, `Enumerable`, `Comparable` and `Numeric`.
     *
     * ### Methods
     * `quot` and `rem`.
     *
     * `quot` and `rem` should satisfy the following law:
     *
            (x / y) * y + (x % y) == x
     *
     * where `/` is `quot` and `%` is `rem`.
     *
     * ### Minimal complete definition
     * All the methods.
     *
     * @{
     */
    template <typename TagL, typename TagR = TagL>
    struct Integral;

    //! Integer division truncated towards zero.
    template <typename M, typename N>
    BOOST_MPL11_DOXYGEN_ALIAS(quot, quot_impl<M, N>);

    template <typename M, typename N>
    using quot_t = typename quot<M, N>::type;


    //! Integer remainder.
    template <typename M, typename N>
    BOOST_MPL11_DOXYGEN_ALIAS(rem, rem_impl<M, N>);

    template <typename M, typename N>
    using rem_t = typename rem<M, N>::type;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTEGRAL_HPP
