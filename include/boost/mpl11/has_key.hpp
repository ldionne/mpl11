/*!
 * @file
 * Defines `boost::mpl11::has_key`.
 */

#ifndef BOOST_MPL11_HAS_KEY_HPP
#define BOOST_MPL11_HAS_KEY_HPP

#include <boost/mpl11/fwd/has_key.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Key>
    struct has_key
        : class_<Sequence>::type::template has_key<Sequence, Key>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_HAS_KEY_HPP
