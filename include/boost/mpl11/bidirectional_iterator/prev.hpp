/*!
 * @file
 * Defines `boost::mpl11::BidirectionalIterator::prev`.
 */

#ifndef BOOST_MPL11_BIDIRECTIONAL_ITERATOR_PREV_HPP
#define BOOST_MPL11_BIDIRECTIONAL_ITERATOR_PREV_HPP

#include <boost/mpl11/bidirectional_iterator/bidirectional_iterator.hpp>
#include <boost/mpl11/detail/not_implemented.hpp>


namespace boost { namespace mpl11 {
    template <typename Iterator>
    struct BidirectionalIterator::prev
        : detail::not_implemented<prev<Iterator>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BIDIRECTIONAL_ITERATOR_PREV_HPP
