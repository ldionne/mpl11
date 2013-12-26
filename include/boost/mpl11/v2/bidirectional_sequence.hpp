/*!
 * @file
 * Defines `boost::mpl11::BidirectionalSequence`.
 */

#ifndef BOOST_MPL11_BIDIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_BIDIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/fwd/bidirectional_sequence.hpp>

#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace defaults { struct BidirectionalSequence { }; }

    template <typename S>
    struct init
        : BidirectionalSequence<typename tag_of<S>::type>::
            template init_impl<S>
    { };

    template <typename S>
    struct last
        : BidirectionalSequence<typename tag_of<S>::type>::
            template last_impl<S>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BIDIRECTIONAL_SEQUENCE_HPP
