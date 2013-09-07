/*!
 * @file
 * Defines `boost::mpl11::concept::RandomAccessIterator`.
 */

#ifndef BOOST_MPL11_CONCEPT_RANDOM_ACCESS_ITERATOR_HPP
#define BOOST_MPL11_CONCEPT_RANDOM_ACCESS_ITERATOR_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/concept/assert.hpp>
#include <boost/mpl11/concept/bidirectional_iterator.hpp>
#include <boost/mpl11/concept/categorizable.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>


namespace boost { namespace mpl11 { namespace concept {
    template <typename I, unsigned int MaxDepth = 2, unsigned int Depth = 0>
    class RandomAccessIterator
        : BidirectionalIterator<I, MaxDepth>,
          Categorizable<I, category::random_access_iterator>
    {
        using Next = typename intrinsic::next<I>::type;
        BOOST_MPL11_CONCEPT_ASSERT(RandomAccessIterator<
            Next, MaxDepth, Depth + 1>);

        using Prior = typename intrinsic::prior<I>::type;
        BOOST_MPL11_CONCEPT_ASSERT(RandomAccessIterator<
            Prior, MaxDepth, Depth + 1
        >);
    };

    template <typename I, unsigned int MaxDepth>
    class RandomAccessIterator<I, MaxDepth, MaxDepth> { };
}}} // end namespace boost::mpl11::concept

#endif // !BOOST_MPL11_CONCEPT_RANDOM_ACCESS_ITERATOR_HPP
