/*!
 * @file
 * Defines `boost::mpl11::shift_right`.
 */

#ifndef BOOST_MPL11_SHIFT_RIGHT_HPP
#define BOOST_MPL11_SHIFT_RIGHT_HPP

#include <boost/mpl11/fwd/shift_right.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename I, typename Shift>
    struct shift_right
        : class_<I>::type::template shift_right<I, Shift>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SHIFT_RIGHT_HPP
