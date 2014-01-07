/*!
 * @file
 * Defines `boost::mpl11::take`.
 */

#ifndef BOOST_MPL11_SEQUENCE_TAKE_HPP
#define BOOST_MPL11_SEQUENCE_TAKE_HPP

#include <boost/mpl11/fwd/sequence.hpp>

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/sequence/sequence.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
    template <typename N, typename Sequence>
    struct take {
#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
        static_assert(N::value >= 0,
        "Invalid usage of `take`: "
        "The number of elements to take must be non-negative.");
#endif

        using type = typename take_c<N::value, Sequence>::type;
    };

    template <detail::std_size_t N, typename Sequence>
    struct take_c { using type = take_c; };

    template <typename Sequence>
    struct take_c<0, Sequence> { using type = empty_sequence; };

    template <detail::std_size_t N, typename Sequence>
    struct tag_of<take_c<N, Sequence>> { using type = sequence_tag; };

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
    // Minimal complete definition
    /////////////////////////////////
    template <detail::std_size_t N, typename Sequence>
    struct head_impl<take_c<N, Sequence>> {
        using type = typename head<Sequence>::type;
    };

    template <detail::std_size_t N, typename Sequence>
    struct tail_impl<take_c<N, Sequence>> {
        using type = take_c<N - 1, typename tail<Sequence>::type>;
    };

    template <detail::std_size_t N, typename Sequence>
    struct is_empty_impl<take_c<N, Sequence>>
        : is_empty<Sequence>
    { };

    template <typename Sequence>
    struct is_empty_impl<take_c<0, Sequence>>
        : true_
    { };


    /////////////////////////////////
    // Optimizations
    /////////////////////////////////
    namespace take_detail {
        template <detail::std_size_t N, typename S,
                  bool = sequence_traits<S>::is_finite>
        struct length_impl;

        template <detail::std_size_t N, typename S>
        struct length_impl<N, S, false> {
            static constexpr auto value = N;
        };

        template <detail::std_size_t N, typename S>
        struct length_impl<N, S, true> {
            static constexpr auto value =
                length<S>::value < N ? length<S>::value : N;
        };
    } // end namespace take_detail

    template <detail::std_size_t N, typename S>
    struct init_impl<take_c<N, S>> {
        using type = take_c<take_detail::length_impl<N, S>::value - 1, S>;
    };

    template <detail::std_size_t N, typename S>
    struct length_impl<take_c<N, S>>
        : size_t<take_detail::length_impl<N, S>::value>
    { };

    template <detail::std_size_t N, typename S, detail::std_size_t Index>
    struct at_c_impl<take_c<N, S>, Index> {
        using type = typename at_c<S, Index>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SEQUENCE_TAKE_HPP
