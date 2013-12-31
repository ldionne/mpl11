/*!
 * @file
 * Defines `boost::mpl11::hash`.
 */

#ifndef BOOST_MPL11_HASH_HPP
#define BOOST_MPL11_HASH_HPP

#include <boost/mpl11/fwd/hash.hpp>

#include <boost/mpl11/class_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Hashable>
    struct hash
        : class_of<Hashable>::type::template hash_impl<Hashable>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_HASH_HPP
