/*!
 * @file
 * Defines `boost::mpl11::join`.
 */

#ifndef BOOST_MPL11_ITERABLE_JOIN_HPP
#define BOOST_MPL11_ITERABLE_JOIN_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/iterable/cons.hpp>
#include <boost/mpl11/partial.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct join<> : empty_sequence { };

    template <typename Iter>
    struct join<Iter> : Iter { };

    template <typename Iter1, typename ...IterN>
    struct join<Iter1, IterN...>
        : if_<is_empty<Iter1>,
            join<IterN...>

        , else_<
            cons<
                head<Iter1>,
                join<tail<Iter1>, IterN...>
            >
        >>
    { };

    namespace rules {
        template <>
        struct length_impl<join<>> : size_t<0> { };

        template <typename Iter>
        struct length_impl<join<Iter>> : length<Iter> { };

        // We add strictly because there could be optimizations.
        template <typename ...Iters>
        struct length_impl<join<Iters...>>
            : plus<typename length<Iters>::type...>::type
        { };

        template <typename Iter1, typename ...IterN, typename F>
        struct unpack_impl<join<Iter1, IterN...>, F>
            : unpack<
                join<IterN...>,
                unpack<Iter1, partial<into<partial>, F>>
            >
        { };
    } // end namespace rules


    // template <typename ...Sn>
    // struct sequence_traits<join<Sn...>> {
    //     static constexpr bool has_O1_length = and_<
    //         bool_<sequence_traits<typename Sn::type>::has_O1_length>...
    //     >::value;

    //     static constexpr bool has_O1_unpack = and_<
    //         bool_<sequence_traits<typename Sn::type>::has_O1_unpack>...
    //     >::value;

    //     static constexpr bool is_finite = and_<
    //         bool_<sequence_traits<typename Sn::type>::is_finite>...
    //     >::value;
    // };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_JOIN_HPP
