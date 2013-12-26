/*!
 * @file
 * Defines `boost::mpl11::init`.
 */

#ifndef BOOST_MPL11_INIT_HPP
#define BOOST_MPL11_INIT_HPP

#include <boost/mpl11/v2/fwd/init.hpp>

#include <boost/mpl11/v2/fwd/bidirectional_sequence.hpp>
#include <boost/mpl11/v2/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename S>
    struct init
        : BidirectionalSequence<typename tag_of<S>::type>::
            template init_impl<S>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INIT_HPP
