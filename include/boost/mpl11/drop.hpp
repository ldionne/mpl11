/*!
 * @file
 * Defines `boost::mpl11::drop`.
 */

#ifndef BOOST_MPL11_DROP_HPP
#define BOOST_MPL11_DROP_HPP

#include <boost/mpl11/fwd/drop.hpp>

#include <boost/mpl11/detail/check_usage.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
    template <typename N, typename Sequence>
    struct drop {
        static_assert(N::value >= 0,
        "Invalid usage of `drop`: "
        "The number of elements to drop must be non-negative.");
        using type = typename drop_c<N::value, Sequence>::type;
    };

    template <detail::std_size_t N, typename Sequence>
    struct drop_c { using type = drop_c; };

    template <typename Sequence>
    struct drop_c<0, Sequence> { using type = Sequence; };

    template <detail::std_size_t N, typename Sequence>
    struct tag_of<drop_c<N, Sequence>> { using type = sequence_tag; };

    template <detail::std_size_t N, typename Sequence>
    struct sequence_traits<drop_c<N, Sequence>> : sequence_traits<Sequence> {
        static constexpr bool has_O1_unpack = false;
    };

    /////////////////////////////////
    // Minimal complete definition
    /////////////////////////////////
    template <detail::std_size_t N, typename Sequence>
    struct head<drop_c<N, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(head<drop_c<N, Sequence>>)
    {
        using type = typename at_c<Sequence, N>::type;
    };

    template <detail::std_size_t N, typename Sequence>
    struct tail<drop_c<N, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(tail<drop_c<N, Sequence>>)
    {
        using type = drop_c<N + 1, Sequence>;
    };

    namespace drop_detail {
        template <bool IsFinite> struct is_empty_impl;

        template <>
        struct is_empty_impl<true> {
            template <detail::std_size_t N, typename Sequence>
            using result = bool_<(N >= length<Sequence>::value)>;
        };

        template <>
        struct is_empty_impl<false> {
            template <detail::std_size_t N, typename Sequence>
            using result = false_;
        };
    } // end namespace drop_detail

    template <typename Sequence>
    struct is_empty<drop_c<0, Sequence>>
        : is_empty<Sequence>
    { };

    template <detail::std_size_t N, typename Sequence>
    struct is_empty<drop_c<N, Sequence>>
        : drop_detail::is_empty_impl<
            sequence_traits<Sequence>::is_finite
        >::template result<N, Sequence>
    { };


    /////////////////////////////////
    // Optimizations
    /////////////////////////////////
    template <detail::std_size_t N, typename S>
    struct length<drop_c<N, S>>
        : size_t<(N >= length<S>::value ? 0 : length<S>::value - N)>
    { };

    template <detail::std_size_t N, typename Sequence>
    struct last<drop_c<N, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(last<drop_c<N, Sequence>>)
    {
        using type = typename last<Sequence>::type;
    };

    template <detail::std_size_t N, typename Sequence>
    struct init<drop_c<N, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(init<drop_c<N, Sequence>>)
    {
        using type = drop_c<N, typename init<Sequence>::type>;
    };

    template <detail::std_size_t N, typename S, detail::std_size_t Index>
    struct at_c<drop_c<N, S>, Index>
        : private BOOST_MPL11_CHECK_USAGE(at_c<drop_c<N, S>, Index>)
    {
        using type = typename at_c<S, N + Index>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DROP_HPP
