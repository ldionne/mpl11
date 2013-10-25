/*!
 * @file
 * Defines `boost::mpl11::SequenceContainer`.
 */

#ifndef BOOST_MPL11_SEQUENCE_CONTAINER_SEQUENCE_CONTAINER_HPP
#define BOOST_MPL11_SEQUENCE_CONTAINER_SEQUENCE_CONTAINER_HPP

#include <boost/mpl11/fwd/sequence_container.hpp>


namespace boost { namespace mpl11 {
    // Elements are stored linearly, like an array. Their index is used for access.
    struct SequenceContainer : Container {
        template <typename SC, typename Position, typename Element>
        struct insert;

        template <typename SC, typename Position, typename Range>
        struct insert_range;

        template <typename SC, typename Position, typename First, typename Last>
        struct insert_range;

        template <typename SC, typename Element>
        struct push_back;

        template <typename SC>
        struct pop_back;

        template <typename SC, typename Element>
        struct push_front;

        template <typename SC>
        struct pop_front;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SEQUENCE_CONTAINER_SEQUENCE_CONTAINER_HPP
