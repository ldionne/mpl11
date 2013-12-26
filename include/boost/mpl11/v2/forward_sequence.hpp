/*!
 * @file
 * Defines `boost::mpl11::ForwardSequence`.
 */

#ifndef BOOST_MPL11_FORWARD_SEQUENCE_HPP
#define BOOST_MPL11_FORWARD_SEQUENCE_HPP

#include <boost/mpl11/v2/fwd/forward_sequence.hpp>

#include <boost/mpl11/detail/lexicographical_compare.hpp>
#include <boost/mpl11/detail/std_equal.hpp>
#include <boost/mpl11/v2/comparable.hpp>
#include <boost/mpl11/v2/orderable.hpp>
#include <boost/mpl11/v2/tags.hpp>


namespace boost { namespace mpl11 {
    namespace defaults { struct ForwardSequence { }; }

    template <>
    struct Comparable<forward_sequence_tag, forward_sequence_tag>
        : defaults::Comparable
    {
        template <typename S1, typename S2>
        using equal_impl = detail::std_equal<S1, S2>;
    };

    template <>
    struct Orderable<forward_sequence_tag, forward_sequence_tag>
        : defaults::Orderable
    {
        template <typename S1, typename S2>
        using less_impl = detail::lexicographical_compare;
    };

    template <typename Tag>
    struct Comparable<forward_sequence_tag, Tag>
        : detail::flip_Comparable<forward_sequence_tag, Tag>
    { };

    template <typename Tag>
    struct Orderable<forward_sequence_tag, Tag>
        : detail::flip_Orderable<forward_sequence_tag, Tag>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FORWARD_SEQUENCE_HPP
