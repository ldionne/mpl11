/*!
 * @file
 * Defines `boost::mpl11::take`.
 */

#ifndef BOOST_MPL11_TAKE_HPP
#define BOOST_MPL11_TAKE_HPP

#include <boost/mpl11/fwd/take.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/bidirectional_sequence.hpp>
#include <boost/mpl11/detail/check_usage.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/drop.hpp>
#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/forward_sequence.hpp>
#include <boost/mpl11/fwd/finite_sequence.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/random_access_sequence.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
    template <typename N, typename Sequence>
    struct take {
        static_assert(N::value >= 0,
        "Invalid usage of `take`: "
        "The number of elements to take must be non-negative.");
        using type = typename take_c<N::value, Sequence>::type;
    };

    template <detail::std_size_t N, typename Sequence>
    struct take_c { using type = take_c; };

    template <typename Sequence>
    struct take_c<0, Sequence> { using type = empty_sequence_t; };

    template <detail::std_size_t N, typename Sequence>
    struct tag_of<take_c<N, Sequence>> {
        using type = random_access_sequence_tag;
    };

    template <detail::std_size_t N, typename Sequence>
    struct sequence_traits<take_c<N, Sequence>> {
        static constexpr bool has_O1_unpack = false;
        static constexpr bool is_finite = true;
        static constexpr bool has_O1_length =
            !sequence_traits<Sequence>::is_finite ||
            sequence_traits<Sequence>::has_O1_length
        ;
    };

    /////////////////////////////////
    // ForwardSequence
    /////////////////////////////////
    template <detail::std_size_t N, typename Sequence>
    struct head<take_c<N, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(head<take_c<N, Sequence>>)
    {
        using type = typename head<Sequence>::type;
    };

    template <detail::std_size_t N, typename Sequence>
    struct tail<take_c<N, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(tail<take_c<N, Sequence>>)
    {
        using type = take_c<N - 1, typename tail<Sequence>::type>;
    };

    template <detail::std_size_t N, typename Sequence>
    struct is_empty<take_c<N, Sequence>>
        : is_empty<Sequence>
    { };

    template <typename Sequence>
    struct is_empty<take_c<0, Sequence>>
        : true_
    { };


    /////////////////////////////////
    // BidirectionalSequence
    /////////////////////////////////
    //! @todo Use a better algorithm here.
    template <detail::std_size_t N, typename Sequence>
    struct last<take_c<N, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(last<take_c<N, Sequence>>)
    {
        using type = typename detail::conditional<
            is_empty<typename tail<Sequence>::type>::value,
            head<Sequence>,
            last<take_c<N - 1, typename tail<Sequence>::type>>
        >::type::type;
    };

    template <typename Sequence>
    struct last<take_c<1, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(last<take_c<1, Sequence>>)
    {
        using type = typename head<Sequence>::type;
    };


    namespace take_detail {
        template <bool IsFinite>
        struct init_impl;

        template <>
        struct init_impl<false> {
            template <detail::std_size_t N, typename Sequence>
            using result = take_c<N - 1, Sequence>;
        };

        template <>
        struct init_impl<true> {
            template <detail::std_size_t N, typename S>
            using result = take_c<
                (length<S>::value < N ? length<S>::value : N) - 1, S
            >;
        };
    } // end namespace take_detail

    template <detail::std_size_t N, typename Sequence>
    struct init<take_c<N, Sequence>>
        : private BOOST_MPL11_CHECK_USAGE(init<take_c<N, Sequence>>)
    {
        using type = typename take_detail::init_impl<
            sequence_traits<Sequence>::is_finite
        >::template result<N, Sequence>;
    };


    /////////////////////////////////
    // FiniteSequence
    /////////////////////////////////
    namespace take_detail {
        template <bool IsFinite> struct length_impl;

        template <>
        struct length_impl<true> {
            template <detail::std_size_t N, typename Sequence>
            using result = size_t<
                (length<Sequence>::value < N ? length<Sequence>::value : N)
            >;
        };

        template <>
        struct length_impl<false> {
            template <detail::std_size_t N, typename Sequence>
            using result = size_t<N>;
        };
    } // end namespace take_detail

    template <detail::std_size_t N, typename Sequence>
    struct length<take_c<N, Sequence>>
        : take_detail::length_impl<
            sequence_traits<Sequence>::is_finite
        >::template result<N, Sequence>
    { };

    //! @todo Use a better algorithm here, if possible.
    template <detail::std_size_t N, typename Sequence, typename F>
    struct unpack<take_c<N, Sequence>, F>
        : unpack<
            take_c<N - N/2, typename drop_c<N/2, Sequence>::type>,
            typename unpack<
                take_c<N/2, Sequence>,
                partial<into<partial>, F>
            >::type
        >
    { };

    namespace take_detail {
        template <bool IsEmpty>
        struct unpack_impl;

        template <>
        struct unpack_impl<true> {
            template <typename Sequence, typename F>
            using result = apply<F>;
        };

        template <>
        struct unpack_impl<false> {
            template <typename Sequence, typename F>
            using result = apply<F, typename head<Sequence>::type>;
        };
    } // end namespace take_detail

    template <typename Sequence, typename F>
    struct unpack<take_c<1, Sequence>, F>
        : take_detail::unpack_impl<
            is_empty<take_c<1, Sequence>>::value
        >::template result<Sequence, F>
    { };

    template <typename Sequence, typename F>
    struct unpack<take_c<0, Sequence>, F>
        : apply<F>
    { };


    /////////////////////////////////
    // RandomAccessSequence
    /////////////////////////////////
    template <detail::std_size_t N, typename Sequence, typename Index>
    struct at<take_c<N, Sequence>, Index>
        : private BOOST_MPL11_CHECK_USAGE(at<take_c<N, Sequence>, Index>)
    {
        using type = typename at<Sequence, Index>::type;
    };

    template <detail::std_size_t N, typename S, typename Start, typename Stop>
    struct slice<take_c<N, S>, Start, Stop>
        : private BOOST_MPL11_CHECK_USAGE(slice<take_c<N, S>, Start, Stop>)
    {
        using type = typename slice<S, Start, Stop>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TAKE_HPP
