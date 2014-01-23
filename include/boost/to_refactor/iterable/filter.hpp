/*!
 * @file
 * Defines `boost::mpl11::filter`.
 */

#ifndef BOOST_MPL11_ITERABLE_FILTER_HPP
#define BOOST_MPL11_ITERABLE_FILTER_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/foldable/none.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/iterable/cons.hpp>
#include <boost/mpl11/iterable/drop_until.hpp>


namespace boost { namespace mpl11 {
    namespace filter_detail {
        template <typename Pred1, typename Pred2>
        struct both {
            using type = both;
            template <typename X>
            using apply = and_<
                mpl11::apply<Pred1, X>,
                mpl11::apply<Pred2, X>
            >;
        };
    } // end namespace filter_detail

    namespace rules {
        template <typename Pred, typename Iter, typename>
        struct filter_impl
            : if_<none<Pred, Iter>,
                empty_sequence,
                cons<
                    head<drop_until<Pred, Iter>>,
                    filter<Pred, tail<drop_until<Pred, Iter>>>
                >
            >
        { };

        template <typename Pred, typename Iter>
        struct is_empty_impl<filter<Pred, Iter>> : none<Pred, Iter> { };

        template <typename Pred1, typename Pred2, typename Iter>
        struct filter_impl<Pred1, filter<Pred2, Iter>>
            : filter<filter_detail::both<Pred1, Pred2>, Iter>
        { };
    } // end namespace rules

    // template <typename Pred, typename S>
    // struct sequence_traits<filter<Pred, S>> {
    //     static constexpr bool has_O1_length = false;
    //     static constexpr bool has_O1_unpack = false;
    //     static constexpr bool is_finite =
    //         sequence_traits<typename S::type>::is_finite;
    // };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_FILTER_HPP
