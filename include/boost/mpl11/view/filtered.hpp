/*!
 * @file
 * Defines `boost::mpl11::view::filtered`.
 */

#ifndef BOOST_MPL11_VIEW_FILTERED_HPP
#define BOOST_MPL11_VIEW_FILTERED_HPP

#include <boost/mpl11/algorithm/find_if.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/deref_fwd.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next_fwd.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/filtered_fwd.hpp>


namespace boost { namespace mpl11 {
//////////////////////////////////////////////////////////////////////////////
// Implementation of the iterator
//////////////////////////////////////////////////////////////////////////////
namespace filtered_detail {
    template <typename First, typename Last, typename Predicate>
    struct iterator;

    template <typename First, typename Last, typename Predicate>
    struct make_filter_iterator
        : identity<
            iterator<
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
struct dispatch<tag::next, filtered_detail::iterator<First, Last, Predicate>>
    : filtered_detail::make_filter_iterator<
        typename next<First>::type, Last, Predicate
    >
{ };

template <typename First, typename Last, typename Predicate>
struct dispatch<tag::deref, filtered_detail::iterator<First, Last, Predicate>>
    : deref<First>
{ };

template <typename F, typename L, typename P>
struct dispatch<tag::category_of, filtered_detail::iterator<F, L, P>>
    : identity<category::forward_iterator>
{ };


//////////////////////////////////////////////////////////////////////////////
// Implementation of the view
//////////////////////////////////////////////////////////////////////////////
namespace filtered_detail {
    template <typename Sequence, typename Predicate>
    using view_impl = view::bounded_by<
        typename make_filter_iterator<
            typename begin<Sequence>::type,
            typename end<Sequence>::type,
            Predicate
        >,
        iterator<
            typename end<Sequence>::type,
            typename end<Sequence>::type,
            Predicate
        >
    >;
} // end namespace filtered_detail

template <typename Sequence, typename Predicate>
struct dispatch<tag::begin, view::filtered<Sequence, Predicate>>
    : begin<filtered_detail::view_impl<Sequence, Predicate>>
{ };

template <typename Sequence, typename Predicate>
struct dispatch<tag::end, view::filtered<Sequence, Predicate>>
    : end<filtered_detail::view_impl<Sequence, Predicate>>
{ };

template <typename Sequence, typename Predicate>
struct dispatch<tag::category_of, view::filtered<Sequence, Predicate>>
    : category_of<filtered_detail::view_impl<Sequence, Predicate>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_FILTERED_HPP
