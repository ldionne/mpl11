/*!
 * @file
 * Defines `boost::mpl11::drop`.
 */

#ifndef BOOST_MPL11_ITERABLE_DROP_HPP
#define BOOST_MPL11_ITERABLE_DROP_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp> // required by forward declaration
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
    template <typename N, typename Iter>
    struct drop {
        static_assert(N::type::value >= 0,
        "Invalid usage of `drop`: "
        "The number of elements to drop must be non-negative.");

        using type = typename rules::drop_impl<N, Iter>::type;
    };
#endif

    namespace rules {
        template <typename N, typename Iter, typename>
        struct drop_impl
            : if_<or_<bool_<N::type::value == 0>, is_empty<Iter>>,
                Iter,
                drop<pred<N>, tail<Iter>>
            >
        { };

        template <typename N1, typename N2, typename Iter>
        struct drop_impl<N1, drop<N2, Iter>> : drop<plus<N1, N2>, Iter> { };

        template <typename N, typename Iter>
        struct head_impl<drop<N, Iter>> : at<Iter, N> { };

        template <typename N, typename Iter>
        struct is_empty_impl<drop<N, Iter>
            , bool_<sequence_traits<typename Iter::type>::has_O1_length>
        >
            : bool_<(N::type::value >= length<Iter>::value)>
        { };

        template <typename N, typename Iter>
        struct length_impl<drop<N, Iter>>
            : size_t<(
                N::type::value < length<Iter>::value
                    ? length<Iter>::value - N::type::value
                    : 0
            )>
        { };

        template <typename N, typename Iter>
        struct last_impl<drop<N, Iter>> : last<Iter> { };

        template <typename N, typename Iter, typename Index>
        struct at_impl<drop<N, Iter>, Index> : at<Iter, plus<N, Index>> { };
    } // end namespace rules

    // template <typename N, typename Iter>
    // struct sequence_traits<drop<N, Iter>> : sequence_traits<Iter> {
    //     static constexpr bool has_O1_unpack = false;
    // };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_DROP_HPP
