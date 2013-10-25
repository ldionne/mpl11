/*!
 * @file
 * Defines `boost::mpl11::Hashable::hash`.
 */

#ifndef BOOST_MPL11_HASHABLE_HASH_HPP
#define BOOST_MPL11_HASHABLE_HASH_HPP

#include <boost/mpl11/hashable/hashable.hpp>


namespace boost { namespace mpl11 {
    template <typename Hashable>
    struct Hashable::hash {
        struct type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_HASHABLE_HASH_HPP
