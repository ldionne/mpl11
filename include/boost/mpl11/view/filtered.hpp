/*!
 * @file
 * Defines `boost::mpl11::view::filtered`.
 */

#ifndef BOOST_MPL11_VIEW_FILTERED_HPP
#define BOOST_MPL11_VIEW_FILTERED_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     *
     * View into the subset of elements of `Sequence` satisfying `Predicate`.
     *
     * Regardless of the category of the underlying sequence, `filtered`
     * is only a forward sequence.
     */
    template <typename Sequence, typename Predicate>
    struct filtered BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view


#include <boost/mpl11/algorithm/find_if.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
namespace filtered_detail {
    template <typename First, typename Last, typename Predicate>
    struct filter_iterator;

    template <typename First, typename Last, typename Predicate>
    struct make_filter_iterator
        : identity<
            filter_iterator<
                typename algorithm::find_if<
                    view::bounded_by<First, Last>, Predicate
                >::type,
                Last,
                Predicate
            >
        >
    { };
} // end namespace filtered_detail

template <typename First, typename Last, typename Predicate>
struct dispatch<
    tag::next, filtered_detail::filter_iterator<First, Last, Predicate>
>
    : filtered_detail::make_filter_iterator<
        typename next<First>::type, Last, Predicate
    >
{ };

template <typename First, typename Last, typename Predicate>
struct dispatch<
    tag::deref, filtered_detail::filter_iterator<First, Last, Predicate>
>
    : deref<First>
{ };

template <typename First, typename Last, typename Predicate>
struct dispatch<
    tag::category_of, filtered_detail::filter_iterator<First, Last, Predicate>
>
    : identity<category::forward_iterator>
{ };

template <typename Op, typename Sequence, typename Predicate, typename ...Args>
struct dispatch<Op, view::filtered<Sequence, Predicate>, Args...>
    : dispatch<
        Op,
        view::bounded_by<
            typename filtered_detail::make_filter_iterator<
                typename begin<Sequence>::type,
                typename end<Sequence>::type,
                Predicate
            >::type,
            typename filtered_detail::make_filter_iterator<
                typename end<Sequence>::type,
                typename end<Sequence>::type,
                Predicate
            >::type
        >,
        Args...
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_FILTERED_HPP
