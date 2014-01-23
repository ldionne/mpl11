/*!
 * @file
 * Defines `boost::mpl11::take`.
 */

#ifndef BOOST_MPL11_ITERABLE_TAKE_HPP
#define BOOST_MPL11_ITERABLE_TAKE_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp> // required by the fwd declaration
#include <boost/mpl11/iterable/cons.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
    template <typename N, typename Iter>
    struct take {
        static_assert(N::type::value >= 0,
        "Invalid usage of `take`: "
        "The number of elements to take must be non-negative.");

        using type = typename rules::take_impl<N, Iter>::type;
    };
#endif

    namespace rules {
        template <typename N, typename Iter, typename>
        struct take_impl
            : if_<or_<bool_<N::type::value == 0>, is_empty<Iter>>,
                empty_sequence,
                cons<head<Iter>, take<pred<N>, tail<Iter>>>
            >
        { };

        template <typename N1, typename N2, typename Iter>
        struct take_impl<N1, take<N2, Iter>> : take<min<N1, N2>, Iter> { };

        template <typename N, typename Iter>
        struct is_empty_impl<take<N, Iter>>
            : or_<bool_<N::type::value == 0>, is_empty<Iter>>
        { };

        template <typename N, typename Iter>
        struct length_impl<take<N, Iter>,
            bool_<!sequence_traits<typename Iter::type>::is_finite>
        >
            : N
        { };

        template <typename N, typename Iter>
        struct length_impl<take<N, Iter>,
            bool_<sequence_traits<typename Iter::type>::has_O1_length>
        >
            : size_t<(
                N::type::value < length<Iter>::value
                    ? N::type::value
                    : length<Iter>::value
            )>
        { };

        template <typename N, typename Iter>
        struct init_impl<take<N, Iter>,
            bool_<sequence_traits<typename Iter::type>::has_O1_length>
        >
            : take<pred<length<take<N, Iter>>>, Iter>
        { };

        template <typename N, typename Iter, typename Index>
        struct at_impl<take<N, Iter>, Index> : at<Iter, Index> { };
    } // end namespace rules

    // template <detail::std_size_t N, typename Iter>
    // struct sequence_traits<take_c<N, Iter>> {
    //     static constexpr bool has_O1_unpack = false;
    //     static constexpr bool is_finite = true;
    //     static constexpr bool has_O1_length =
    //         !sequence_traits<typename Iter::type>::is_finite ||
    //         sequence_traits<typename Iter::type>::has_O1_length
    //     ;
    // };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_TAKE_HPP
