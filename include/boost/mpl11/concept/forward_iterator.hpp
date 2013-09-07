/*!
 * @file
 * Defines `boost::mpl11::concept::ForwardIterator`.
 */

#ifndef BOOST_MPL11_CONCEPT_FORWARD_ITERATOR_HPP
#define BOOST_MPL11_CONCEPT_FORWARD_ITERATOR_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/concept/assert.hpp>
#include <boost/mpl11/concept/categorizable.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/next.hpp>


namespace boost { namespace mpl11 { namespace concept {
    template <typename I, unsigned int MaxDepth = 2, unsigned int Depth = 0>
    class ForwardIterator
        : Categorizable<I, category::forward_iterator>
    {
        using Deref = typename intrinsic::deref<I>::type;

        using Next = typename intrinsic::next<I>::type;
        BOOST_MPL11_CONCEPT_ASSERT(ForwardIterator<Next, MaxDepth, Depth + 1>);
    };

    template <typename I, unsigned int MaxDepth>
    class ForwardIterator<I, MaxDepth, MaxDepth> { };
}}} // end namespace boost::mpl11::concept

#endif // !BOOST_MPL11_CONCEPT_FORWARD_ITERATOR_HPP
