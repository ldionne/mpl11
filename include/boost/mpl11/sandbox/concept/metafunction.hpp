/*!
 * @file
 * This file defines the `boost::mpl11::Metafunction` concept.
 */

#ifndef BOOST_MPL11_CONCEPT_METAFUNCTION_HPP
#define BOOST_MPL11_CONCEPT_METAFUNCTION_HPP

#include <boost/concept/usage.hpp>


namespace boost { namespace mpl11 {
template <typename F>
class Metafunction : Categorizable<F, category::metafunction> {
    using Result = typename F::type;
};

template <typename F, typename ...Args>
class MetafunctionClass : Categorizable<F, category::metafunction_class> {
    using Apply = typename detail::nested_apply<F, Args...>::type;
    BOOST_MPL11_CONCEPT_ASSERT(Metafunction<Apply>);
};

template <typename S>
class ExtensibleSequence
    : Categorizable<S, category::extensible_sequence>
{
    using InsertAt = typename insert<S, Pos, X>::type;
    BOOST_MPL11_CONCEPT_ASSERT(ExtensibleSequence<InsertAt>);

    using InsertRange = typename insert_range<S, Pos, R>::type;
    BOOST_MPL11_CONCEPT_ASSERT(ExtensibleSequence<InsertRange>);

    using EraseAt = typename erase<S, Pos>::type;
    BOOST_MPL11_CONCEPT_ASSERT(ExtensibleSequence<EraseAt>);

    using EraseRange = typename erase<S, Pos, Last>::type;
    BOOST_MPL11_CONCEPT_ASSERT(ExtensibleSequence<EraseRange>);

    using Clear = typename clear<S>::type;
    BOOST_MPL11_CONCEPT_ASSERT(ExtensibleSequence<Clear>);
};

template <typename S>
class FrontExtensibleSequence
    : ExtensibleSequence<S>,
      Categorizable<S, category::front_extensible_sequence>
{
    using PushFront = typename push_front<S, X>::type;
    BOOST_MPL11_CONCEPT_ASSERT(FrontExtensibleSequence<PushFront>);

    using PopFront = typename pop_front<S>::type;
    BOOST_MPL11_CONCEPT_ASSERT(FrontExtensibleSequence<PopFront>);

    using Front = typename front<S>::type;
};

template <typename S>
class BackExtensibleSequence
    : ExtensibleSequence<S>,
      Categorizable<S, category::back_extensible_sequence>
{
    using PushBack = typename push_back<S, X>::type;
    BOOST_MPL11_CONCEPT_ASSERT(BackExtensibleSequence<PushBack>);

    using PopBack = typename pop_back<S>::type;
    BOOST_MPL11_CONCEPT_ASSERT(BackExtensibleSequence<PopBack>);

    using Back = typename back<S>::type;
};

template <typename S>
class AssociativeSequence
    : ForwardSequence<S>,
      Categorizable<S, category::associative_sequence>
{
    using HasKey = typename has_key<S, K>::type;
    BOOST_MPL11_CONCEPT_ASSERT(BooleanIntegralConstant<HasKey>);

    // Differences from the original MPL:
    // - Not considering `count` as an intrinsic.
    // - `order` does not exist anymore.

    using AtWithoutDefault = typename at<S, K>::type;
    using AtWithDefault = typename at<S, K, Default>::type;
    using Key = typename key_of<S, X>::type;
    using Value = typename value_of<S, X>::type;
};

template <typename S>
class ExtensibleAssociativeSequence
    : AssociativeSequence<S>
      Categorizable<S, category::extensible_associative_sequence>
{
    using Insert = typename insert<S, X>::type;
    BOOST_MPL11_CONCEPT_ASSERT(ExtensibleAssociativeSequence<Insert>);

    using EraseKey = typename erase_key<S, K>::type;
    BOOST_MPL11_CONCEPT_ASSERT(ExtensibleAssociativeSequence<EraseKey>);

    using EraseAt = typename erase<S, Pos>::type;
    BOOST_MPL11_CONCEPT_ASSERT(ExtensibleAssociativeSequence<EraseAt>);

    using EraseRange = typename erase<S, Pos, Last>::type;
    BOOST_MPL11_CONCEPT_ASSERT(ExtensibleAssociativeSequence<EraseRange>);

    using Clear = typename clear<S>::type;
    BOOST_MPL11_CONCEPT_ASSERT(ExtensibleAssociativeSequence<Clear>);
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONCEPT_METAFUNCTION_HPP
