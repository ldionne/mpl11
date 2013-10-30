/*!
 * @file
 * Defines `boost::mpl11::Hashable`.
 */

#ifndef BOOST_MPL11_HASHABLE_HPP
#define BOOST_MPL11_HASHABLE_HPP

#include <boost/mpl11/fwd/hashable.hpp>

#include <boost/mpl11/comparable.hpp>


namespace boost { namespace mpl11 {
    struct Hashable : Comparable {
        //! Returns a type uniquely associated to `H`.
        template <typename H>
        struct hash_impl {
            struct type;
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_HASHABLE_HPP
