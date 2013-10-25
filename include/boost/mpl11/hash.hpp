/*!
 * @file
 * Defines `boost::mpl11::hash`.
 */

#ifndef BOOST_MPL11_HASH_HPP
#define BOOST_MPL11_HASH_HPP

#include <boost/mpl11/fwd/hash.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Hashable>
    struct hash
        : class_<Hashable>::type::template hash<Hashable>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_HASH_HPP
