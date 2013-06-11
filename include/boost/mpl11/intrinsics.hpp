/*!
 * @file
 * This file defines the intrinsic metafunctions of the library.
 */

#ifndef BOOST_MPL11_INTRINSICS_HPP
#define BOOST_MPL11_INTRINSICS_HPP

#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/size_t.hpp>
#include <boost/mpl11/traits.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace extension {
    template <typename Tag> struct advance_impl;
    template <typename Tag> struct at_impl;
    template <typename Tag> struct back_impl;
    template <typename Tag> struct begin_impl;
    template <typename Tag> struct clear_impl;
    template <typename Tag> struct deref_impl;
    template <typename Tag> struct distance_impl;
    template <typename Tag> struct empty_impl;
    template <typename Tag> struct end_impl;
    template <typename Tag> struct erase_impl;
    template <typename Tag> struct erase_key_impl;
    template <typename Tag> struct first_impl;
    template <typename Tag> struct front_impl;
    template <typename Tag> struct has_key_impl;
    template <typename Tag> struct insert_impl;
    template <typename Tag> struct insert_range_impl;
    template <typename Tag> struct key_type_impl;
    template <typename Tag> struct next_impl;
    template <typename Tag> struct order_impl;
    template <typename Tag> struct pop_back_impl;
    template <typename Tag> struct pop_front_impl;
    template <typename Tag> struct prior_impl;
    template <typename Tag> struct push_back_impl;
    template <typename Tag> struct push_front_impl;
    template <typename Tag> struct second_impl;
    template <typename Tag> struct size_impl;
    template <typename Tag> struct value_type_impl;
}

namespace intrinsic_detail {
template <template <typename> class Impl, typename Receiver, typename ...Args>
struct intrinsic
    : apply_raw<
        Impl<typename traits::tag_of<Receiver>::type>,
        Receiver, Args...
    >
{ };
}

//////////////////////////////////////////////////////////////////////////////
template <typename Iterator, typename N>
struct advance
    : intrinsic_detail::intrinsic<
        extension::advance_impl, Iterator, N
    >
{ };

//////////////////////////////////////////////////////////////////////////////
namespace at_detail { struct none; }
template <typename AssociativeSequence,
          typename Key,
          typename Default = at_detail::none>
struct at
    : intrinsic_detail::intrinsic<
        extension::at_impl, AssociativeSequence, Key, Default
    >
{ };

template <typename Sequence, typename N>
struct at<Sequence, N, at_detail::none>
    : intrinsic_detail::intrinsic<
        extension::at_impl, Sequence, N
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence, size_t<0>::value_type N>
struct at_c
    : at<Sequence, size_t<N>>
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence>
struct back
    : intrinsic_detail::intrinsic<
        extension::back_impl, Sequence
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence>
struct begin
    : intrinsic_detail::intrinsic<
        extension::begin_impl, Sequence
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence>
struct clear
    : intrinsic_detail::intrinsic<
        extension::clear_impl, Sequence
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Iterator>
struct deref
    : intrinsic_detail::intrinsic<
        extension::deref_impl, Iterator
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename First, typename Last>
struct distance
    : intrinsic_detail::intrinsic<
        extension::distance_impl, First, Last
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence>
struct empty
    : intrinsic_detail::intrinsic<
        extension::empty_impl, Sequence
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence>
struct end
    : intrinsic_detail::intrinsic<
        extension::end_impl, Sequence
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Iterator> struct next;
template <typename Sequence, typename First, typename Last = typename next<First>::type>
struct erase
    : intrinsic_detail::intrinsic<
        extension::erase_impl, Sequence, First, Last
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename AssociativeSequence, typename Key>
struct erase_key
    : intrinsic_detail::intrinsic<
        extension::erase_key_impl, AssociativeSequence, Key
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Pair>
struct first
    : intrinsic_detail::intrinsic<
        extension::first_impl, Pair
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence>
struct front
    : intrinsic_detail::intrinsic<
        extension::front_impl, Sequence
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename AssociativeSequence, typename Key>
struct has_key
    : intrinsic_detail::intrinsic<
        extension::has_key_impl, AssociativeSequence, Key
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence, typename Position, typename Element>
struct insert
    : intrinsic_detail::intrinsic<
        extension::insert_impl, Sequence, Position, Element
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence, typename Position, typename Range>
struct insert_range
    : intrinsic_detail::intrinsic<
        extension::insert_range_impl, Sequence, Position, Range
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename AssociativeSequence, typename Element>
struct key_type
    : intrinsic_detail::intrinsic<
        extension::key_type_impl, AssociativeSequence, Element
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Iterator>
struct next
    : intrinsic_detail::intrinsic<
        extension::next_impl, Iterator
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename AssociativeSequence, typename Key>
struct order
    : intrinsic_detail::intrinsic<
        extension::order_impl, AssociativeSequence, Key
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence>
struct pop_back
    : intrinsic_detail::intrinsic<
        extension::pop_back_impl, Sequence
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence>
struct pop_front
    : intrinsic_detail::intrinsic<
        extension::pop_front_impl, Sequence
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Iterator>
struct prior
    : intrinsic_detail::intrinsic<
        extension::prior_impl, Iterator
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence, typename Element>
struct push_back
    : intrinsic_detail::intrinsic<
        extension::push_back_impl, Sequence, Element
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence, typename Element>
struct push_front
    : intrinsic_detail::intrinsic<
        extension::push_front_impl, Sequence, Element
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Pair>
struct second
    : intrinsic_detail::intrinsic<
        extension::second_impl, Pair
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename Sequence>
struct size
    : intrinsic_detail::intrinsic<
        extension::size_impl, Sequence
    >
{ };

//////////////////////////////////////////////////////////////////////////////
template <typename AssociativeSequence, typename Element>
struct value_type
    : intrinsic_detail::intrinsic<
        extension::value_type_impl, AssociativeSequence, Element
    >
{ };
}}}

#endif // !BOOST_MPL11_INTRINSICS_HPP
