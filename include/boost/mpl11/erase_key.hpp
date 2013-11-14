/*!
 * @file
 * Defines `boost::mpl11::erase_key`.
 */

#ifndef BOOST_MPL11_ERASE_KEY_HPP
#define BOOST_MPL11_ERASE_KEY_HPP

#include <boost/mpl11/fwd/erase_key.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Container, typename Key>
    struct erase_key
        : class_of<Container>::type::template erase_key_impl<Container, Key>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ERASE_KEY_HPP
