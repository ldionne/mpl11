/*!
 * @file
 * Defines `boost::mpl11::head`.
 */

#ifndef BOOST_MPL11_HEAD_HPP
#define BOOST_MPL11_HEAD_HPP

#include <boost/mpl11/v2/fwd/head.hpp>

#include <boost/mpl11/v2/fwd/forward_sequence.hpp>
#include <boost/mpl11/v2/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename S>
    struct head
        : ForwardSequence<typename tag_of<S>::type>::template head_impl<S>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_HEAD_HPP
