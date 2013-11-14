/*!
 * @file
 * Defines `boost::mpl11::erase_keys`.
 */

#ifndef BOOST_MPL11_ERASE_KEYS_HPP
#define BOOST_MPL11_ERASE_KEYS_HPP

#include <boost/mpl11/fwd/erase_keys.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Container, typename Keys>
    struct erase_keys
        : class_of<Container>::type::template erase_keys_impl<Container, Keys>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ERASE_KEYS_HPP
