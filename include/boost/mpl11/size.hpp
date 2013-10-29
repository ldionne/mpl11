/*!
 * @file
 * Defines `boost::mpl11::size`.
 */

#ifndef BOOST_MPL11_SIZE_HPP
#define BOOST_MPL11_SIZE_HPP

#include <boost/mpl11/fwd/size.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename I>
    struct size
        : class_of<I>::type::template size_impl<I>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SIZE_HPP
