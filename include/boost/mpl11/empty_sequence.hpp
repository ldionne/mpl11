/*!
 * @file
 * Defines `boost::mpl11::empty_sequence`.
 */

#ifndef BOOST_MPL11_EMPTY_SEQUENCE_HPP
#define BOOST_MPL11_EMPTY_SEQUENCE_HPP

#include <boost/mpl11/fwd/empty_sequence.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/bidirectional_sequence.hpp>
#include <boost/mpl11/detail/check_usage.hpp>
#include <boost/mpl11/forward_sequence.hpp>
#include <boost/mpl11/fwd/finite_sequence.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/random_access_sequence.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct tag_of<empty_sequence> {
        using type = random_access_sequence_tag;
    };

    template <>
    struct sequence_traits<empty_sequence> : defaults::sequence_traits {
        static constexpr bool has_O1_size = true;
        static constexpr bool has_O1_unpack = true;
        static constexpr bool is_finite = true;
    };

    template <>
    struct is_empty<empty_sequence>
        : true_
    { };

    template <>
    struct length<empty_sequence>
        : size_t<0>
    { };

    template <typename F>
    struct unpack<empty_sequence, F>
        : apply<F>
    { };

    template <typename Start, typename Stop>
    struct slice<empty_sequence, Start, Stop>
        : private BOOST_MPL11_CHECK_USAGE(slice<empty_sequence, Start, Stop>)
    {
        using type = empty_sequence;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EMPTY_SEQUENCE_HPP
