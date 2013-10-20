/*!
 * @file
 * Forward declares `boost::mpl11::shift_left`.
 */

#ifndef BOOST_MPL11_FWD_SHIFT_LEFT_HPP
#define BOOST_MPL11_FWD_SHIFT_LEFT_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct shift_left; }

    template <typename T, typename Shift>
    struct shift_left
        : dispatch<tag::shift_left, T, Shift>
    { };

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup bitwise_operators
     *
     * Returns the result of bitwise _shift left_ operation on an
     * @ref IntegralConstant.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
     * `identity<integral_c<decltype(T::value << Shift::value),
     *                      T::value << Shift::value>>`.
     */
    template <>
    struct shift_left<IntegralConstant, IntegralConstant> { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SHIFT_LEFT_HPP
