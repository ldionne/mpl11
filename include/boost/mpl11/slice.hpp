/*!
 * @file
 * Defines `boost::mpl11::slice`.
 */

#ifndef BOOST_MPL11_SLICE_HPP
#define BOOST_MPL11_SLICE_HPP

#include <boost/mpl11/fwd/slice.hpp>

#include <boost/mpl11/class_of.hpp>
#include <boost/mpl11/integral_c.hpp> // required for fwd/slice.hpp


namespace boost { namespace mpl11 {
    template <typename S, typename Start, typename Stop>
    struct slice
        : class_of<S>::type::template slice_impl<S, Start, Stop>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SLICE_HPP
