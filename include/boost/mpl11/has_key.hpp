/*!
 * @file
 * Defines `boost::mpl11::has_key`.
 */

#ifndef BOOST_MPL11_HAS_KEY_HPP
#define BOOST_MPL11_HAS_KEY_HPP

#include <boost/mpl11/fwd/has_key.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Seq, typename Key>
    struct has_key
        : class_of<Seq>::type::template has_key_impl<Seq, Key>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_HAS_KEY_HPP
