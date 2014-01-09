/*!
 * @file
 * Defines `boost::mpl11::sort_by`.
 */

#ifndef BOOST_MPL11_ITERABLE_SORT_BY_HPP
#define BOOST_MPL11_ITERABLE_SORT_BY_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/compose.hpp>
#include <boost/mpl11/iterable/cons.hpp>
#include <boost/mpl11/iterable/filter.hpp>
#include <boost/mpl11/iterable/join.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/quote.hpp>


namespace boost { namespace mpl11 {
    namespace sort_by_detail {
        template <typename S>
        struct is_unary
            : is_empty<typename tail<S>::type>
        { };

        template <bool MustBeSorted> struct sort_by_impl;

        template <>
        struct sort_by_impl<false> {
            template <typename Pred, typename Seq>
            using result = Seq;
        };

        template <>
        struct sort_by_impl<true> {
            template <
                typename Pred,
                typename Seq,
                typename Pivot = head_t<Seq>,
                typename Rest = tail_t<Seq>,
                typename IsGreater = partial<Pred, Pivot>,
                typename IsSmallerEq = compose<quote<not_>, IsGreater>,
                typename SmallerEq = filter_t<IsSmallerEq, Rest>,
                typename Greater = filter_t<IsGreater, Rest>
            >
            using result = typename join<
                typename sort_by<Pred, SmallerEq>::type,
                typename cons<Pivot,
                    typename sort_by<Pred, Greater>::type
                >::type
            >::type;
        };
    } // end namespace sort_by_detail

    template <typename Pred, typename Seq>
    struct sort_by {
        using type = typename sort_by_detail::sort_by_impl<
            !or_<is_empty<Seq>, sort_by_detail::is_unary<Seq>>::value
        >::template result<Pred, Seq>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_SORT_BY_HPP
