/*!
 * @file
 * Defines `boost::mpl11::ForwardSequence`.
 */

#ifndef BOOST_MPL11_FORWARD_SEQUENCE_HPP
#define BOOST_MPL11_FORWARD_SEQUENCE_HPP

#include <boost/mpl11/fwd/forward_sequence.hpp>

#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/lexicographical_compare.hpp>
#include <boost/mpl11/detail/std_equal.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace defaults { struct ForwardSequence { }; }

    template <typename S>
    struct head
        : ForwardSequence<typename tag_of<S>::type>::template head_impl<S>
    { };

    template <typename S>
    struct is_empty
        : ForwardSequence<typename tag_of<S>::type>::template is_empty_impl<S>
    { };

    template <typename S>
    struct tail
        : ForwardSequence<typename tag_of<S>::type>::template tail_impl<S>
    { };

    template <>
    struct Comparable<forward_sequence_tag, forward_sequence_tag>
        : defaults::Comparable
    {
        template <typename S1, typename S2>
        using equal_impl = detail::std_equal<S1, S2>;
    };

    template <typename Tag>
    struct Comparable<forward_sequence_tag, Tag>
        : detail::flip_Comparable<forward_sequence_tag, Tag>
    { };


    template <>
    struct Orderable<forward_sequence_tag, forward_sequence_tag>
        : defaults::Orderable
    {
        template <typename S1, typename S2>
        using less_impl = detail::lexicographical_compare<S1, S2>;
    };

    template <typename Tag>
    struct Orderable<forward_sequence_tag, Tag>
        : detail::flip_Orderable<forward_sequence_tag, Tag>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_SEQUENCE_HPP
