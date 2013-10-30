/*!
 * @file
 * Defines `boost::mpl11::size`.
 */

#ifndef BOOST_MPL11_SIZE_HPP
#define BOOST_MPL11_SIZE_HPP

#include <boost/mpl11/fwd/size.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence>
    struct size
        : class_of<Sequence>::type::template size_impl<Sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SIZE_HPP
