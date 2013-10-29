/*!
 * @file
 * Defines `boost::mpl11::erase_key`.
 */

#ifndef BOOST_MPL11_ERASE_KEY_HPP
#define BOOST_MPL11_ERASE_KEY_HPP

#include <boost/mpl11/fwd/erase_key.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Key>
    struct erase_key
        : class_<Sequence>::type::template erase_key<Sequence, Key>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ERASE_KEY_HPP
