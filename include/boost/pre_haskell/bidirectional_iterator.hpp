/*!
 * @file
 * Defines `boost::mpl11::BidirectionalIterator`.
 */

#ifndef BOOST_MPL11_BIDIRECTIONAL_ITERATOR_HPP
#define BOOST_MPL11_BIDIRECTIONAL_ITERATOR_HPP

#include <boost/mpl11/fwd/bidirectional_iterator.hpp>

#include <boost/mpl11/detail/move.hpp>
#include <boost/mpl11/forward_iterator.hpp> // required by fwd declaration
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/prev.hpp>


namespace boost { namespace mpl11 {
    template <typename Iterator, typename N, bool Backwards>
    struct BidirectionalIterator::advance_impl
        : detail::move<prev, Iterator, -N::value>
    { };

    template <typename Iterator, typename N>
    struct BidirectionalIterator::advance_impl<Iterator, N, false>
        : detail::move<next, Iterator, N::value>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BIDIRECTIONAL_ITERATOR_HPP
