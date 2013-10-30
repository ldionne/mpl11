/*!
 * @file
 * Defines `boost::mpl11::back`.
 */

#ifndef BOOST_MPL11_BACK_HPP
#define BOOST_MPL11_BACK_HPP

#include <boost/mpl11/fwd/back.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename I>
    struct back
        : class_of<I>::type::template back_impl<I>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BACK_HPP
