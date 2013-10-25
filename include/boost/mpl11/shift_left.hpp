/*!
 * @file
 * Defines `boost::mpl11::shift_left`.
 */

#ifndef BOOST_MPL11_SHIFT_LEFT_HPP
#define BOOST_MPL11_SHIFT_LEFT_HPP

#include <boost/mpl11/fwd/shift_left.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename I, typename Shift>
    struct shift_left
        : class_<I>::type::template shift_left<I, Shift>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SHIFT_LEFT_HPP
