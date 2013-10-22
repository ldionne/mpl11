/*!
 * @file
 * Defines `boost::mpl11::BidirectionalIterator::advance`.
 */

#ifndef BOOST_MPL11_BIDIRECTIONAL_ITERATOR_ADVANCE_HPP
#define BOOST_MPL11_BIDIRECTIONAL_ITERATOR_ADVANCE_HPP

#include <boost/mpl11/bidirectional_iterator/bidirectional_iterator.hpp>
#include <boost/mpl11/detail/move.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/prev.hpp>


namespace boost { namespace mpl11 {
    template <typename Iterator, typename N> // negative N
    struct BidirectionalIterator::advance<Iterator, N, true>
        : detail::move<prev, Iterator, -N::value>
    { };

    template <typename Iterator, typename N> // positive N
    struct BidirectionalIterator::advance<Iterator, N, false>
        : detail::move<next, Iterator, N::value>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BIDIRECTIONAL_ITERATOR_ADVANCE_HPP
