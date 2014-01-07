/*!
 * @file
 * Defines `boost::mpl11::drop`.
 */

#ifndef BOOST_MPL11_SEQUENCE_DROP_HPP
#define BOOST_MPL11_SEQUENCE_DROP_HPP

#include <boost/mpl11/fwd/sequence.hpp>

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/sequence/sequence.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
    template <typename N, typename Sequence>
    struct drop {
#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
        static_assert(N::value >= 0,
        "Invalid usage of `drop`: "
        "The number of elements to drop must be non-negative.");
#endif

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
    namespace drop_detail {
        template <bool IsFinite> struct is_empty_helper;

        template <>
        struct is_empty_helper<true> {
            template <detail::std_size_t N, typename Sequence>
            using result = bool_<(N >= length<Sequence>::value)>;
        };

        template <>
        struct is_empty_helper<false> {
            template <detail::std_size_t N, typename Sequence>
            using result = false_;
        };
    } // end namespace drop_detail

    template <detail::std_size_t N, typename Sequence>
    struct head_impl<drop_c<N, Sequence>> {
        using type = typename at_c<Sequence, N>::type;
    };

    template <detail::std_size_t N, typename Sequence>
    struct tail_impl<drop_c<N, Sequence>> {
        using type = drop_c<N + 1, Sequence>;
    };

    template <typename Sequence>
    struct is_empty_impl<drop_c<0, Sequence>>
        : is_empty<Sequence>
    { };

    template <detail::std_size_t N, typename Sequence>
    struct is_empty_impl<drop_c<N, Sequence>>
        : drop_detail::is_empty_helper<
            sequence_traits<Sequence>::is_finite
        >::template result<N, Sequence>
    { };

    /////////////////////////////////
    // Optimizations
    /////////////////////////////////
    template <detail::std_size_t N, typename S>
    struct length_impl<drop_c<N, S>>
        : size_t<(N >= length<S>::value ? 0 : length<S>::value - N)>
    { };

    template <detail::std_size_t N, typename Sequence>
    struct last_impl<drop_c<N, Sequence>> {
        using type = typename last<Sequence>::type;
    };

    template <detail::std_size_t N, typename Sequence>
    struct init_impl<drop_c<N, Sequence>> {
        using type = drop_c<N, typename init<Sequence>::type>;
    };

    template <detail::std_size_t N, typename S, detail::std_size_t Index>
    struct at_c_impl<drop_c<N, S>, Index> {
        using type = typename at_c<S, N + Index>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SEQUENCE_DROP_HPP
