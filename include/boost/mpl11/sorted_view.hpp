/*!
 * @file
 * Defines `boost::mpl11::sorted_view`.
 */

#ifndef BOOST_MPL11_SORTED_VIEW_HPP
#define BOOST_MPL11_SORTED_VIEW_HPP

#include <boost/mpl11/fwd/sorted_view.hpp>
#include <boost/mpl11/less.hpp>  // for the default `Predicate`
#include <boost/mpl11/quote.hpp> //

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/category/forward_sequence.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/filtered_view.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/joined_view.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/single_view.hpp>


namespace boost { namespace mpl11 {
namespace sorted_detail {
    template <typename S, typename Pred, bool = is_empty<S>::type::value>
    struct quick_sort;

    template <typename S, typename Pred>
    struct quick_sort<S, Pred, true>
        : identity<S>
    { };

    template <typename S, typename Pred>
    struct quick_sort<S, Pred, false> {
        using Pivot = typename begin<S>::type;

        //! @todo Use a lazily partitionned view instead, if possible.
        using RestOfSequence = iterator_range<
            typename next<Pivot>::type, typename end<S>::type
        >;
        using IsLessThanPivot = typename lambda<
            apply_wrap<Pred, _1, typename deref<Pivot>::type>
        >::type;
        using LessThanPivot = filtered_view<
            RestOfSequence, IsLessThanPivot
        >;
        using GreaterThanPivot = filtered_view<
            RestOfSequence, not_<apply_wrap<IsLessThanPivot, _1>>
        >;
        using type = joined_view<
            typename quick_sort<LessThanPivot, Pred>::type,
            single_view<typename deref<Pivot>::type>,
            typename quick_sort<GreaterThanPivot, Pred>::type
        >;
    };

    template <typename Sequence, typename Predicate>
    using view_impl = typename quick_sort<
        Sequence, typename lambda<Predicate>::type
    >::type;
} // end namespace sorted_detail

template <typename Sequence, typename Predicate>
struct dispatch<tag::begin, sorted_view<Sequence, Predicate>>
    : begin<sorted_detail::view_impl<Sequence, Predicate>>
{ };

template <typename Sequence, typename Predicate>
struct dispatch<tag::end, sorted_view<Sequence, Predicate>>
    : end<sorted_detail::view_impl<Sequence, Predicate>>
{ };

template <typename Sequence, typename Predicate>
struct dispatch<tag::category_of, sorted_view<Sequence, Predicate>>
    : identity<category::forward_sequence>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SORTED_VIEW_HPP
