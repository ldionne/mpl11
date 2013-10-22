/*!
 * @file
 * Defines `boost::mpl11::view::sorted`.
 */

#ifndef BOOST_MPL11_VIEW_SORTED_HPP
#define BOOST_MPL11_VIEW_SORTED_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/apply_wrap.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/is_empty.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/operator/less.hpp>
#include <boost/mpl11/operator/not.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/filtered.hpp>
#include <boost/mpl11/view/joined.hpp>
#include <boost/mpl11/view/single_element.hpp>
#include <boost/mpl11/view/sorted_fwd.hpp>


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
        using RestOfSequence = view::bounded_by<
            typename next<Pivot>::type, typename end<S>::type
        >;
        using IsLessThanPivot = typename lambda<
            apply_wrap<Pred, _1, typename deref<Pivot>::type>
        >::type;
        using LessThanPivot = view::filtered<
            RestOfSequence, IsLessThanPivot
        >;
        using GreaterThanPivot = view::filtered<
            RestOfSequence, not_<apply_wrap<IsLessThanPivot, _1>>
        >;
        using type = view::joined<
            typename quick_sort<LessThanPivot, Pred>::type,
            view::single_element<typename deref<Pivot>::type>,
            typename quick_sort<GreaterThanPivot, Pred>::type
        >;
    };

    template <typename Sequence, typename Predicate>
    using view_impl = typename quick_sort<
        Sequence, typename lambda<Predicate>::type
    >::type;
} // end namespace sorted_detail

template <typename Sequence, typename Predicate>
struct dispatch<tag::begin, view::sorted<Sequence, Predicate>>
    : begin<sorted_detail::view_impl<Sequence, Predicate>>
{ };

template <typename Sequence, typename Predicate>
struct dispatch<tag::end, view::sorted<Sequence, Predicate>>
    : end<sorted_detail::view_impl<Sequence, Predicate>>
{ };

template <typename Sequence, typename Predicate>
struct dispatch<tag::category_of, view::sorted<Sequence, Predicate>>
    : identity<category::forward_sequence>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_SORTED_HPP
