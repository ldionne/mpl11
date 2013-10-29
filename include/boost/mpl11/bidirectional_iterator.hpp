/*!
 * @file
 * Defines `boost::mpl11::BidirectionalIterator`.
 */

#ifndef BOOST_MPL11_BIDIRECTIONAL_ITERATOR_HPP
#define BOOST_MPL11_BIDIRECTIONAL_ITERATOR_HPP

#include <boost/mpl11/fwd/bidirectional_iterator.hpp>

#include <boost/mpl11/detail/move.hpp>
#include <boost/mpl11/forward_iterator.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/prev.hpp>


namespace boost { namespace mpl11 {
    struct BidirectionalIterator : ForwardIterator {
        /*!
         * Performs `N::value` applications of `mpl11::next` or `mpl11::prev`
         * to `Iterator`, depending on the sign of `N::value`.
         */
        template <typename Iterator, typename N, bool = (N::value < 0)>
        struct advance_impl
            : detail::move<prev, Iterator, -N::value>
        { };

        template <typename Iterator, typename N>
        struct advance_impl<Iterator, N, false>
            : detail::move<next, Iterator, N::value>
        { };

        //! This operation must be provided by the user.
        template <typename Iterator>
        struct prev_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BIDIRECTIONAL_ITERATOR_HPP
