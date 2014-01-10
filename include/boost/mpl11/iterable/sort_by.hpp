/*!
 * @file
 * Defines `boost::mpl11::sort_by`.
 */

#ifndef BOOST_MPL11_ITERABLE_SORT_BY_HPP
#define BOOST_MPL11_ITERABLE_SORT_BY_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/compose.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/iterable/cons.hpp>
#include <boost/mpl11/iterable/filter.hpp>
#include <boost/mpl11/iterable/join.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/partial.hpp>
#include <boost/mpl11/quote.hpp>


namespace boost { namespace mpl11 {
    namespace sort_by_detail {
        template <
            typename Pred,
            typename Iter,
            typename Pivot = head<Iter>,
            typename Rest = tail<Iter>,
            typename IsGreater = partial<Pred, Pivot>,
            typename IsSmallerEq = compose<quote<not_>, IsGreater>,
            typename SmallerEq = filter<IsSmallerEq, Rest>,
            typename Greater = filter<IsGreater, Rest>
        >
        using sort_by_impl = join<
            sort_by<Pred, SmallerEq>,
            cons<Pivot, sort_by<Pred, Greater>>
        >;
    } // end namespace sort_by_detail

    template <typename Pred, typename Iter>
    struct sort_by
        : if_<or_<is_empty<Iter>, is_empty<tail<Iter>>>,
            Iter,
            sort_by_detail::sort_by_impl<Pred, Iter>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_SORT_BY_HPP
