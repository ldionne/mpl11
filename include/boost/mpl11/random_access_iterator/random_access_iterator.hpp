/*!
 * @file
 * Defines `boost::mpl11::RandomAccessIterator`.
 */

#ifndef BOOST_MPL11_RANDOM_ACCESS_ITERATOR_RANDOM_ACCESS_ITERATOR_HPP
#define BOOST_MPL11_RANDOM_ACCESS_ITERATOR_RANDOM_ACCESS_ITERATOR_HPP

#include <boost/mpl11/fwd/random_access_iterator.hpp>

#include <boost/mpl11/bidirectional_iterator/bidirectional_iterator.hpp>
#include <boost/mpl11/orderable/orderable.hpp>


namespace boost { namespace mpl11 {
    struct RandomAccessIterator : BidirectionalIterator, Orderable {
        // must be O(1), no default implementation
        template <typename Iterator, typename N>
        struct advance;

        // must be O(1), no default implementation
        template <typename Iterator, typename N>
        struct distance;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_RANDOM_ACCESS_ITERATOR_RANDOM_ACCESS_ITERATOR_HPP
