/*!
 * @file
 * Defines `boost::mpl11::take`.
 */

#ifndef BOOST_MPL11_ITERABLE_TAKE_HPP
#define BOOST_MPL11_ITERABLE_TAKE_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterable/iterable.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
    template <typename N, typename Iter>
    struct take {
#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
        static_assert(N::value >= 0,
        "Invalid usage of `take`: "
        "The number of elements to take must be non-negative.");
#endif

        using type = typename take_c<N::value, Iter>::type;
    };

    template <detail::std_size_t N, typename Iter>
    struct take_c { using type = take_c; };

    template <typename Iter>
    struct take_c<0, Iter> { using type = empty_sequence; };

    template <detail::std_size_t N, typename Iter>
    struct tag_of<take_c<N, Iter>> { using type = iterable_tag; };

    template <detail::std_size_t N, typename Iter>
    struct sequence_traits<take_c<N, Iter>> {
        static constexpr bool has_O1_unpack = false;
        static constexpr bool is_finite = true;
        static constexpr bool has_O1_length =
            !sequence_traits<Iter>::is_finite ||
            sequence_traits<Iter>::has_O1_length
        ;
    };

    /////////////////////////////////
    // Minimal complete definition
    /////////////////////////////////
    template <detail::std_size_t N, typename Iter>
    struct head_impl<take_c<N, Iter>> {
        using type = typename head<Iter>::type;
    };

    template <detail::std_size_t N, typename Iter>
    struct tail_impl<take_c<N, Iter>> {
        using type = take_c<N - 1, typename tail<Iter>::type>;
    };

    template <detail::std_size_t N, typename Iter>
    struct is_empty_impl<take_c<N, Iter>>
        : is_empty<Iter>
    { };

    template <typename Iter>
    struct is_empty_impl<take_c<0, Iter>>
        : true_
    { };


    /////////////////////////////////
    // Optimizations
    /////////////////////////////////
    namespace take_detail {
        template <detail::std_size_t N, typename Iter,
                  bool = sequence_traits<Iter>::is_finite>
        struct length_impl;

        template <detail::std_size_t N, typename Iter>
        struct length_impl<N, Iter, false> {
            static constexpr auto value = N;
        };

        template <detail::std_size_t N, typename Iter>
        struct length_impl<N, Iter, true> {
            static constexpr auto value =
                length<Iter>::value < N ? length<Iter>::value : N;
        };
    } // end namespace take_detail

    template <detail::std_size_t N, typename Iter>
    struct init_impl<take_c<N, Iter>> {
        using type = take_c<
            take_detail::length_impl<N, Iter>::value - 1, Iter
        >;
    };

    template <detail::std_size_t N, typename Iter>
    struct length_impl<take_c<N, Iter>>
        : size_t<take_detail::length_impl<N, Iter>::value>
    { };

    template <detail::std_size_t N, typename Iter, detail::std_size_t Index>
    struct at_c_impl<take_c<N, Iter>, Index> {
        using type = typename at_c<Iter, Index>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_TAKE_HPP
