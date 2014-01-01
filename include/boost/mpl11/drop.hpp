/*!
 * @file
 * Defines `boost::mpl11::drop`.
 */

#ifndef BOOST_MPL11_DROP_HPP
#define BOOST_MPL11_DROP_HPP

#include <boost/mpl11/fwd/drop.hpp>

#include <boost/mpl11/bidirectional_sequence.hpp>
#include <boost/mpl11/detail/check_usage.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/forward_sequence.hpp>
#include <boost/mpl11/fwd/finite_sequence.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/random_access_sequence.hpp>
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
    struct tag_of<drop_c<N, Sequence>> {
        using type = random_access_sequence_tag;
    };

    template <detail::std_size_t N, typename Sequence>
    struct sequence_traits<drop_c<N, Sequence>> : sequence_traits<Sequence> {
        static constexpr bool has_O1_unpack = false;
    };

    /////////////////////////////////
    // ForwardSequence
    /////////////////////////////////
    namespace drop_detail {
        template <detail::std_size_t N, typename Sequence,
            bool = N == 0 || is_empty<Sequence>::value>
        struct skip_prefix;

        template <detail::std_size_t N, typename Sequence>
        struct skip_prefix<N, Sequence, true> {
            using type = Sequence;
        };

        template <detail::std_size_t N, typename Sequence>
        struct skip_prefix<N, Sequence, false> {
            using type = typename skip_prefix<
                N - 1, typename tail<Sequence>::type
            >::type;
        };
    } // end namespace drop_detail

    //! @todo Use a better algorithm.
    //! @note We could use `at` when we have a `RandomAccessSequence`.
    template <detail::std_size_t N, typename Sequence>
    struct head<drop_c<N, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(head<drop_c<N, Sequence>>)
    {
        using type = typename head<
            typename drop_detail::skip_prefix<N, Sequence>::type
        >::type;
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
    // FiniteSequence
    /////////////////////////////////
    template <detail::std_size_t N, typename S>
    struct length<drop_c<N, S>>
        : size_t<(N >= length<S>::value ? 0 : length<S>::value - N)>
    { };

    //! @todo Use a better algorithm.
    template <detail::std_size_t N, typename Sequence, typename F>
    struct unpack<drop_c<N, Sequence>, F>
        : unpack<typename drop_detail::skip_prefix<N, Sequence>::type, F>
    { };


    /////////////////////////////////
    // BidirectionalSequence
    /////////////////////////////////
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


    /////////////////////////////////
    // RandomAccessSequence
    /////////////////////////////////
    template <detail::std_size_t N, typename Sequence, typename Index>
    struct at<drop_c<N, Sequence>, Index>
        : private BOOST_MPL11_CHECK_USAGE(at<drop_c<N, Sequence>, Index>)
    {
        using type = typename at_c<Sequence, N + Index::value>::type;
    };

    namespace drop_detail {
        template <bool IsEmpty>
        struct slice_impl;

        template <>
        struct slice_impl<true> {
            template <
                detail::std_size_t N, typename S,
                typename Start, typename Stop
            >
            using result = empty_sequence;
        };

        template <>
        struct slice_impl<false> {
            template <
                detail::std_size_t N, typename S,
                typename Start, typename Stop
            >
            using result = typename slice_c<
                S, Start::value + N, Stop::value + N
            >::type;
        };
    } // end namespace drop_detail

    template <detail::std_size_t N, typename S, typename Start, typename Stop>
    struct slice<drop_c<N, S>, Start, Stop>
        : private BOOST_MPL11_CHECK_USAGE(slice<drop_c<N, S>, Start, Stop>)
    {
        using type = typename drop_detail::slice_impl<
            is_empty<drop_c<N, S>>::value
        >::template result<N, S, Start, Stop>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DROP_HPP
