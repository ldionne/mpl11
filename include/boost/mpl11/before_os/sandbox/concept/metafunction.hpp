/*!
 * @file
 * This file defines the `boost::mpl11::Metafunction` concept.
 */

#ifndef BOOST_MPL11_CONCEPT_METAFUNCTION_HPP
#define BOOST_MPL11_CONCEPT_METAFUNCTION_HPP

#include <boost/concept/usage.hpp>


namespace boost { namespace mpl11 {
template <unsigned long>
struct always_true
    : true_
{ };

#define BOOST_MPL11_FORCE_INSTANTIATION(/* type to instantiate */...)       \
    static_assert(always_true<sizeof(__VA_ARGS__)>::value, "")              \
/**/

#define BOOST_MPL11_CONCEPT_ASSERT(/* concept checking class */...)         \
    BOOST_MPL11_FORCE_INSTANTIATION(__VA_ARGS__)                            \
/**/

#define BOOST_MPL11_INSTANTIATE_TEST(/* unit test */...)                    \
    BOOST_MPL11_FORCE_INSTANTIATION(__VA_ARGS__)                            \
/**/



template <typename T, typename ...Categories>
class Categorizable {
    // `and_` expects at least two arguments, hence the two trailing `true_`s.
    static_assert(and_<
        std::is_base_of<Categories, typename category_of<T>::type>...,
        true_, true_
    >::value, "");
};


template <typename F>
class Metafunction : Categorizable<F, category::metafunction> {
    using Result = typename F::type;
};

template <typename F, typename ...Args>
class MetafunctionClass : Categorizable<F, category::metafunction_class> {
    using Apply = typename detail::nested_apply<F, Args...>::type;
    BOOST_MPL11_CONCEPT_ASSERT(Metafunction<Apply>);
};


template <typename N>
class IntegralConstant
    : Categorizable<N, category::integral_constant>,
      RandomAccessIterator<N>
{
    using ValueType = typename N::value_type;

    static constexpr ValueType value1 = N::value,
                               value2 = N{};
};

template <typename N>
class BooleanIntegralConstant : IntegralConstant<N> {
    static_assert(is_same<typename N::value_type, bool>::value, "");
};


template <typename I>
class ForwardIterator
    : Categorizable<I, category::forward_iterator>
{
    using Deref = typename deref<I>::type;

    using Next = typename next<I>::type;
    BOOST_MPL11_CONCEPT_ASSERT(ForwardIterator<Next>);
};

template <typename I>
class BidirectionalIterator
    : ForwardIterator<I>,
      Categorizable<I, category::bidirectional_iterator>
{
    using Next = typename next<I>::type;
    BOOST_MPL11_CONCEPT_ASSERT(BidirectionalIterator<Next>);

    using Prior = typename prior<I>::type;
    BOOST_MPL11_CONCEPT_ASSERT(BidirectionalIterator<Prior>);
};

template <typename I>
class RandomAccessIterator
    : BidirectionalIterator<I>,
      Categorizable<I, category::random_access_iterator>
{
    using Next = typename next<I>::type;
    BOOST_MPL11_CONCEPT_ASSERT(RandomAccessIterator<Next>);

    using Prior = typename prior<I>::type;
    BOOST_MPL11_CONCEPT_ASSERT(RandomAccessIterator<Prior>);
};



template <typename S>
class ForwardSequence
    : Categorizable<S, category::forward_sequence>
{
    using First = typename begin<S>::type;
    BOOST_MPL11_CONCEPT_ASSERT(ForwardIterator<First>);

    // There is a little issue because the original MPL says that
    // past-the-end iterators are ForwardIterators and that they are
    // simply not dereferenceable. However, introducing this into
    // concept checking makes the concept very weak.
    using Last = typename end<S>::type;
    BOOST_MPL11_CONCEPT_ASSERT(Categorizable<Last, category::forward_iterator>);

    using Size = typename size<S>::type;
    BOOST_MPL11_CONCEPT_ASSERT(IntegralConstant<Size>);

    using IsEmpty = typename is_empty<S>::type;
    BOOST_MPL11_CONCEPT_ASSERT(BooleanIntegralConstant<IsEmpty>);

    using Front = typename front<S>::type;
};

template <typename S>
class BidirectionalSequence
    : ForwardSequence<S>,
      Categorizable<S, category::bidirectional_sequence>
{
    using First = typename begin<S>::type;
    BOOST_MPL11_CONCEPT_ASSERT(BidirectionalIterator<First>);

    using Last = typename end<S>::type;
    BOOST_MPL11_CONCEPT_ASSERT(Categorizable<Last, category::bidirectional_iterator, category::forward_iterator>);

    using Back = typename back<S>::type;
};

template <typename S>
class RandomAccessSequence
    : BidirectionalSequence<S>,
      Categorizable<S, category::random_access_sequence>
{
    using First = typename begin<S>::type;
    BOOST_MPL11_CONCEPT_ASSERT(RandomAccessIterator<First>);

    using Last = typename end<S>::type;
    BOOST_MPL11_CONCEPT_ASSERT(Categorizable<Last, category::random_access_iterator, category::bidirectional_iterator, category::forward_iterator>);

    // How to deal with the fact that `S` could be empty?
    using N = integral_constant_archetype<>;
    using SomeElement = typename at<S, N>::type;
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
