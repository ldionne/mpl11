/*!
 * @file
 * Defines `boost::mpl11::concept::BidirectionalIterator`.
 */

#ifndef BOOST_MPL11_CONCEPT_BIDIRECTIONAL_ITERATOR_HPP
#define BOOST_MPL11_CONCEPT_BIDIRECTIONAL_ITERATOR_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/concept/assert.hpp>
#include <boost/mpl11/concept/categorizable.hpp>
#include <boost/mpl11/concept/forward_iterator.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>


namespace boost { namespace mpl11 { namespace concept {
    template <typename I, unsigned int MaxDepth = 2, unsigned int Depth = 0>
    class BidirectionalIterator
        : ForwardIterator<I, MaxDepth>,
          Categorizable<I, category::bidirectional_iterator>
    {
        using Next = typename intrinsic::next<I>::type;
        BOOST_MPL11_CONCEPT_ASSERT(BidirectionalIterator<
            Next, MaxDepth, Depth + 1
        >);

        using Prior = typename intrinsic::prior<I>::type;
        BOOST_MPL11_CONCEPT_ASSERT(BidirectionalIterator<
            Prior, MaxDepth, Depth + 1
        >);
    };

    template <typename I, unsigned int MaxDepth>
    class BidirectionalIterator<I, MaxDepth, MaxDepth> { };
}}} // end namespace boost::mpl11::concept

#endif // !BOOST_MPL11_CONCEPT_BIDIRECTIONAL_ITERATOR_HPP
