/*!
 * @file
 * Defines `boost::mpl11::BidirectionalIterator`.
 */

#ifndef BOOST_MPL11_BIDIRECTIONAL_ITERATOR_BIDIRECTIONAL_ITERATOR_HPP
#define BOOST_MPL11_BIDIRECTIONAL_ITERATOR_BIDIRECTIONAL_ITERATOR_HPP

#include <boost/mpl11/fwd/bidirectional_iterator.hpp>

#include <boost/mpl11/forward_iterator/forward_iterator.hpp>


namespace boost { namespace mpl11 {
    struct BidirectionalIterator : ForwardIterator {
        // allows negative N
        template <typename Iterator, typename N, bool = (N::value < 0)>
        struct advance;

        // no default implementation
        template <typename Iterator>
        struct prev;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BIDIRECTIONAL_ITERATOR_BIDIRECTIONAL_ITERATOR_HPP
