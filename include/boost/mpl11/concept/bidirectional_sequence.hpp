/*!
 * @file
 * Defines `boost::mpl11::concept::BidirectionalSequence`.
 */

#ifndef BOOST_MPL11_CONCEPT_BIDIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_CONCEPT_BIDIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/concept/assert.hpp>
#include <boost/mpl11/concept/bidirectional_iterator.hpp>
#include <boost/mpl11/concept/categorizable.hpp>
#include <boost/mpl11/concept/forward_sequence.hpp>
#include <boost/mpl11/intrinsic/back.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>


namespace boost { namespace mpl11 { namespace concept {
    template <typename S, unsigned int MaxDepth = 2>
    class BidirectionalSequence
        : ForwardSequence<S, MaxDepth>,
          Categorizable<S, category::bidirectional_sequence>
    {
        using Begin = typename intrinsic::begin<S>::type;
        BOOST_MPL11_CONCEPT_ASSERT(BidirectionalIterator<Begin, MaxDepth>);

        using End = typename intrinsic::end<S>::type;
        BOOST_MPL11_CONCEPT_ASSERT(BidirectionalIterator<End, MaxDepth>);

        using Back = typename intrinsic::back<S>::type;
    };
}}} // end namespace boost::mpl11::concept

#endif // !BOOST_MPL11_CONCEPT_BIDIRECTIONAL_SEQUENCE_HPP
