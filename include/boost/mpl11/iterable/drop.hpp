/*!
 * @file
 * Defines `boost::mpl11::drop`.
 */

#ifndef BOOST_MPL11_ITERABLE_DROP_HPP
#define BOOST_MPL11_ITERABLE_DROP_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterable/iterable.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
    template <typename N, typename Iter>
    struct drop {
#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
        static_assert(N::value >= 0,
        "Invalid usage of `drop`: "
        "The number of elements to drop must be non-negative.");
#endif

        using type = typename drop_c<N::value, Iter>::type;
    };

    template <detail::std_size_t N, typename Iter>
    struct drop_c { using type = drop_c; };

    template <typename Iter>
    struct drop_c<0, Iter> { using type = Iter; };

    template <detail::std_size_t N, typename Iter>
    struct tag_of<drop_c<N, Iter>> { using type = iterable_tag; };

    template <detail::std_size_t N, typename Iter>
    struct sequence_traits<drop_c<N, Iter>> : sequence_traits<Iter> {
        static constexpr bool has_O1_unpack = false;
    };

    /////////////////////////////////
    // Minimal complete definition
    /////////////////////////////////
    namespace drop_detail {
        template <bool IsFinite> struct is_empty_helper;

        template <>
        struct is_empty_helper<true> {
            template <detail::std_size_t N, typename Iter>
            using result = bool_<(N >= length<Iter>::value)>;
        };

        template <>
        struct is_empty_helper<false> {
            template <detail::std_size_t N, typename Iter>
            using result = false_;
        };
    } // end namespace drop_detail

    template <detail::std_size_t N, typename Iter>
    struct head_impl<drop_c<N, Iter>> {
        using type = typename at_c<Iter, N>::type;
    };

    template <detail::std_size_t N, typename Iter>
    struct tail_impl<drop_c<N, Iter>> {
        using type = drop_c<N + 1, Iter>;
    };

    template <typename Iter>
    struct is_empty_impl<drop_c<0, Iter>>
        : is_empty<Iter>
    { };

    template <detail::std_size_t N, typename Iter>
    struct is_empty_impl<drop_c<N, Iter>>
        : drop_detail::is_empty_helper<
            sequence_traits<Iter>::is_finite
        >::template result<N, Iter>
    { };

    /////////////////////////////////
    // Optimizations
    /////////////////////////////////
    template <detail::std_size_t N, typename S>
    struct length_impl<drop_c<N, S>>
        : size_t<(N >= length<S>::value ? 0 : length<S>::value - N)>
    { };

    template <detail::std_size_t N, typename Iter>
    struct last_impl<drop_c<N, Iter>> {
        using type = typename last<Iter>::type;
    };

    template <detail::std_size_t N, typename Iter>
    struct init_impl<drop_c<N, Iter>> {
        using type = drop_c<N, typename init<Iter>::type>;
    };

    template <detail::std_size_t N, typename Iter, detail::std_size_t Index>
    struct at_c_impl<drop_c<N, Iter>, Index> {
        using type = typename at_c<Iter, N + Index>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_DROP_HPP
