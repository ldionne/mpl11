/*!
 * @file
 * Defines `boost::mpl11::ForwardIterator::distance`.
 */

#ifndef BOOST_MPL11_FORWARD_ITERATOR_DISTANCE_HPP
#define BOOST_MPL11_FORWARD_ITERATOR_DISTANCE_HPP

#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/forward_iterator/forward_iterator.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/quote.hpp>


namespace boost { namespace mpl11 {
    template <typename First, typename Last>
    struct ForwardIterator::distance
        : foldl<
            iterator_range<First, Last>,
            ulong<0>,
            quote<next>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_ITERATOR_DISTANCE_HPP
