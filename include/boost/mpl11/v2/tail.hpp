/*!
 * @file
 * Defines `boost::mpl11::tail`.
 */

#ifndef BOOST_MPL11_TAIL_HPP
#define BOOST_MPL11_TAIL_HPP

#include <boost/mpl11/v2/fwd/tail.hpp>

#include <boost/mpl11/v2/fwd/forward_sequence.hpp>
#include <boost/mpl11/v2/tag_of.hpp>


namespace boost { namespace mpl11 {
    template <typename S>
    struct tail
        : ForwardSequence<typename tag_of<S>::type>::template tail_impl<S>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TAIL_HPP
