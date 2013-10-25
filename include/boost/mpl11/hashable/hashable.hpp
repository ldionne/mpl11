/*!
 * @file
 * Defines `boost::mpl11::Hashable`.
 */

#ifndef BOOST_MPL11_HASHABLE_HASHABLE_HPP
#define BOOST_MPL11_HASHABLE_HASHABLE_HPP

#include <boost/mpl11/fwd/hashable.hpp>

#include <boost/mpl11/comparable/comparable.hpp>


namespace boost { namespace mpl11 {
    struct Hashable : Comparable {
        template <typename Hashable>
        struct hash;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_HASHABLE_HASHABLE_HPP
