/*!
 * @file
 * Defines `boost::mpl11::BidirectionalIterable`.
 */

#ifndef BOOST_MPL11_BIDIRECTIONAL_ITERABLE_BIDIRECTIONAL_ITERABLE_HPP
#define BOOST_MPL11_BIDIRECTIONAL_ITERABLE_BIDIRECTIONAL_ITERABLE_HPP

#include <boost/mpl11/fwd/bidirectional_iterable.hpp>

#include <boost/mpl11/forward_iterable/forward_iterable.hpp>


namespace boost { namespace mpl11 {
    struct BidirectionalIterable : ForwardIterable {
        template <typename I>
        struct back;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BIDIRECTIONAL_ITERABLE_BIDIRECTIONAL_ITERABLE_HPP
