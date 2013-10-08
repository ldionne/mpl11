/*!
 * @file
 * Forward declares `boost::mpl11::shift_right`.
 */

#ifndef BOOST_MPL11_OPERATOR_SHIFT_RIGHT_FWD_HPP
#define BOOST_MPL11_OPERATOR_SHIFT_RIGHT_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct shift_right; }

    template <typename T, typename Shift>
    struct shift_right
        : dispatch<tag::shift_right, T, Shift>
    { };

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup bitwise_operators
     *
     * Returns the result of bitwise _shift right_ operation on an
     * @ref IntegralConstant.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
     * `identity<integral_c<decltype(T::value >> Shift::value),
     *                      T::value >> Shift::value>>`.
     */
    template <>
    struct shift_right<IntegralConstant, IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OPERATOR_SHIFT_RIGHT_FWD_HPP
