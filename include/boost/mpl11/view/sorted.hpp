/*!
 * @file
 * Defines `boost::mpl11::view::sorted`.
 */

#ifndef BOOST_MPL11_VIEW_SORTED_HPP
#define BOOST_MPL11_VIEW_SORTED_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     *
     * View onto the elements of a sequence sorted according to the
     * ordering relation `Predicate`.
     *
     * If left unspecified, `Predicate` is equivalent to `less<_1, _2>`.
     */
    template <typename Sequence, typename Predicate = detail::optional>
    struct sorted BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view


#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/apply_wrap.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/is_empty.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/operator/less.hpp>
#include <boost/mpl11/operator/not.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/filtered.hpp>
#include <boost/mpl11/view/joined.hpp>
#include <boost/mpl11/view/single_element.hpp>


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
} // end namespace sorted_detail

template <typename Operation, typename S, typename Pred, typename ...Args>
struct dispatch<Operation, view::sorted<S, Pred>, Args...>
    : dispatch<
        Operation,
        typename sorted_detail::quick_sort<
            S, typename lambda<Pred>::type
        >::type,
        Args...
    >
{ };

template <typename Operation, typename S, typename ...Args>
struct dispatch<Operation, view::sorted<S>, Args...>
    : dispatch<Operation, view::sorted<S, quote<less>>, Args...>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_SORTED_HPP
