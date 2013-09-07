/*!
 * @file
 * Defines `boost::mpl11::concept::RandomAccessSequence`.
 */

#ifndef BOOST_MPL11_CONCEPT_RANDOM_ACCESS_SEQUENCE_HPP
#define BOOST_MPL11_CONCEPT_RANDOM_ACCESS_SEQUENCE_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/concept/assert.hpp>
#include <boost/mpl11/concept/bidirectional_sequence.hpp>
#include <boost/mpl11/concept/categorizable.hpp>
#include <boost/mpl11/concept/random_access_iterator.hpp>
#include <boost/mpl11/intrinsic/at.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>


namespace boost { namespace mpl11 { namespace concept {
    template <typename S, unsigned int MaxDepth = 2>
    class RandomAccessSequence
        : BidirectionalSequence<S, MaxDepth>,
          Categorizable<S, category::random_access_sequence>
    {
        using Begin = typename intrinsic::begin<S>::type;
        BOOST_MPL11_CONCEPT_ASSERT(RandomAccessIterator<Begin, MaxDepth>);

        using End = typename intrinsic::end<S>::type;
        BOOST_MPL11_CONCEPT_ASSERT(RandomAccessIterator<End, MaxDepth>);

        // How to deal with the fact that `S` could be empty?
        using N = integral_constant_archetype<>;
        using SomeElement = typename intrinsic::at<S, N>::type;
    };
}}} // end namespace boost::mpl11::concept

#endif // !BOOST_MPL11_CONCEPT_RANDOM_ACCESS_SEQUENCE_HPP
