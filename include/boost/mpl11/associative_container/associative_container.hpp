/*!
 * @file
 * Defines `boost::mpl11::AssociativeContainer`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_CONTAINER_ASSOCIATIVE_CONTAINER_HPP
#define BOOST_MPL11_ASSOCIATIVE_CONTAINER_ASSOCIATIVE_CONTAINER_HPP

#include <boost/mpl11/fwd/associative_container.hpp>

#include <boost/mpl11/container/container.hpp>


namespace boost { namespace mpl11 {
    // Elements are indexed by a custom key.
    struct AssociativeContainer : Container {
        template <typename AC, typename Element>
        struct insert;

        template <typename AC, typename Range>
        struct insert_range;

        template <typename AC, typename First, typename Last>
        struct insert_range;

        template <typename AC, typename Key>
        struct erase_key;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_CONTAINER_ASSOCIATIVE_CONTAINER_HPP
