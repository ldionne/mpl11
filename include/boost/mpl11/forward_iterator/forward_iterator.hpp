/*!
 * @file
 * Defines `boost::mpl11::ForwardIterator`.
 */

#ifndef BOOST_MPL11_FORWARD_ITERATOR_FORWARD_ITERATOR_HPP
#define BOOST_MPL11_FORWARD_ITERATOR_FORWARD_ITERATOR_HPP

#include <boost/mpl11/fwd/forward_iterator.hpp>

#include <boost/mpl11/comparable/comparable.hpp>


namespace boost { namespace mpl11 {
    struct ForwardIterator : Comparable {
        template <typename Iterator, typename N>
        struct advance;

        template <typename First, typename Last>
        struct distance;

        // no default implementation
        template <typename Iterator>
        struct next;

        // no default implementation
        template <typename Iterator>
        struct deref;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_ITERATOR_FORWARD_ITERATOR_HPP
