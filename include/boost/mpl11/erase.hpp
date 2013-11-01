/*!
 * @file
 * Defines `boost::mpl11::erase`.
 */

#ifndef BOOST_MPL11_ERASE_HPP
#define BOOST_MPL11_ERASE_HPP

#include <boost/mpl11/fwd/erase.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Container, typename Position>
    struct erase
        : class_of<Container>::type::template erase_impl<Container, Position>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ERASE_HPP
