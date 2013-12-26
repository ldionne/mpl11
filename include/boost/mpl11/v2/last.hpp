/*!
 * @file
 * Defines `boost::mpl11::last`.
 */

#ifndef BOOST_MPL11_LAST_HPP
#define BOOST_MPL11_LAST_HPP

#include <boost/mpl11/v2/fwd/last.hpp>

#include <boost/mpl11/v2/fwd/bidirectional_sequence.hpp>
#include <boost/mpl11/v2/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename S>
    struct last
        : BidirectionalSequence<typename tag_of<S>::type>::
            template last_impl<S>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LAST_HPP
