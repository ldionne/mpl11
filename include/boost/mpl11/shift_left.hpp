/*!
 * @file
 * Defines `boost::mpl11::shift_left`.
 */

#ifndef BOOST_MPL11_SHIFT_LEFT_HPP
#define BOOST_MPL11_SHIFT_LEFT_HPP

#include <boost/mpl11/fwd/shift_left.hpp>

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    template <typename T, typename Shift>
    struct dispatch<tag::default_<tag::shift_left>, T, Shift>
        : identity<
            integral_c<
                decltype(T::value << Shift::value),
                T::value << Shift::value
            >
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SHIFT_LEFT_HPP
