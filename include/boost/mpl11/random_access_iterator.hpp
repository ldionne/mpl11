/*!
 * @file
 * Defines `boost::mpl11::RandomAccessIterator`.
 */

#ifndef BOOST_MPL11_RANDOM_ACCESS_ITERATOR_HPP
#define BOOST_MPL11_RANDOM_ACCESS_ITERATOR_HPP

#include <boost/mpl11/fwd/random_access_iterator.hpp>

#include <boost/mpl11/bidirectional_iterator.hpp>
#include <boost/mpl11/orderable.hpp>


namespace boost { namespace mpl11 {
    struct RandomAccessIterator : BidirectionalIterator, Orderable {
        //! This operation must be O(1) and provided by the user.
        template <typename Iterator, typename N>
        struct advance_impl;

        //! This operation must be O(1) and provided by the user.
        template <typename First, typename Last>
        struct distance_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_RANDOM_ACCESS_ITERATOR_HPP
