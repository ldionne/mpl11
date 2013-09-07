/*!
 * @file
 * Defines `boost::mpl11::concept::ForwardSequence`.
 */

#ifndef BOOST_MPL11_CONCEPT_FORWARD_SEQUENCE_HPP
#define BOOST_MPL11_CONCEPT_FORWARD_SEQUENCE_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/concept/assert.hpp>
#include <boost/mpl11/concept/boolean_integral_constant.hpp>
#include <boost/mpl11/concept/categorizable.hpp>
#include <boost/mpl11/concept/forward_iterator.hpp>
#include <boost/mpl11/concept/integral_constant.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/front.hpp>
#include <boost/mpl11/intrinsic/is_empty.hpp>
#include <boost/mpl11/intrinsic/size.hpp>


namespace boost { namespace mpl11 { namespace concept {
    template <typename I, unsigned int MaxDepth = 2>
    class ForwardSequence
        : Categorizable<S, category::forward_sequence>
    {
        using Begin = typename intrinsic::begin<S>::type;
        BOOST_MPL11_CONCEPT_ASSERT(ForwardIterator<Begin, MaxDepth>);

        // There is a little issue because the original MPL says that
        // past-the-end iterators are ForwardIterators and that they are
        // simply not dereferenceable. However, introducing this into
        // concept checking makes the concept very weak.
        using End = typename intrinsic::end<S>::type;
        BOOST_MPL11_CONCEPT_ASSERT(ForwardIterator<End, MaxDepth>);
        // BOOST_MPL11_CONCEPT_ASSERT(Categorizable<
        //     End, category::forward_iterator
        // >);

        using Size = typename intrinsic::size<S>::type;
        BOOST_MPL11_CONCEPT_ASSERT(IntegralConstant<Size>);

        using IsEmpty = typename intrinsic::is_empty<S>::type;
        BOOST_MPL11_CONCEPT_ASSERT(BooleanIntegralConstant<IsEmpty>);

        using Front = typename intrinsic::front<S>::type;
    };
}}} // end namespace boost::mpl11::concept

#endif // !BOOST_MPL11_CONCEPT_FORWARD_SEQUENCE_HPP
