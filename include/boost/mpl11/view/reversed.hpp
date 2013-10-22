/*!
 * @file
 * Defines `boost::mpl11::view::reversed`.
 */

#ifndef BOOST_MPL11_VIEW_REVERSED_HPP
#define BOOST_MPL11_VIEW_REVERSED_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/deref_fwd.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>
#include <boost/mpl11/operator/equal_to_fwd.hpp>
#include <boost/mpl11/operator/less_fwd.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/reversed_fwd.hpp>


namespace boost { namespace mpl11 {
//////////////////////////////////////////////////////////////////////////////
// Implementation of the iterator
//////////////////////////////////////////////////////////////////////////////
namespace reversed_detail {
    template <typename Iterator>
    struct iterator;
}

template <typename Iterator>
struct dispatch<tag::next, reversed_detail::iterator<Iterator>>
    : identity<
        reversed_detail::iterator<typename prior<Iterator>::type>
    >
{ };

template <typename Iterator>
struct dispatch<tag::prior, reversed_detail::iterator<Iterator>>
    : identity<
        reversed_detail::iterator<typename next<Iterator>::type>
    >
{ };

template <typename Iterator>
struct dispatch<tag::deref, reversed_detail::iterator<Iterator>>
    : deref<typename prior<Iterator>::type>
{ };

template <typename Iterator>
struct dispatch<tag::category_of, reversed_detail::iterator<Iterator>>
    : category_of<Iterator>
{ };

template <typename It1, typename It2>
struct dispatch<tag::equal_to,
    reversed_detail::iterator<It1>,
    reversed_detail::iterator<It2>
>
    : equal_to<It1, It2>
{ };

template <typename It1, typename It2>
struct dispatch<tag::less,
    reversed_detail::iterator<It1>,
    reversed_detail::iterator<It2>
>
    : less<It2, It1>
{ };


//////////////////////////////////////////////////////////////////////////////
// Implementation of the view
//////////////////////////////////////////////////////////////////////////////
namespace reversed_detail {
    template <typename Sequence>
    using view_impl = view::bounded_by<
        iterator<typename end<Sequence>::type>,
        iterator<typename begin<Sequence>::type>
    >;
} // end namespace reversed_detail

template <typename Sequence>
struct dispatch<tag::begin, view::reversed<Sequence>>
    : begin<reversed_detail::view_impl<Sequence>>
{ };

template <typename Sequence>
struct dispatch<tag::end, view::reversed<Sequence>>
    : end<reversed_detail::view_impl<Sequence>>
{ };

template <typename Sequence>
struct dispatch<tag::category_of, view::reversed<Sequence>>
    : category_of<reversed_detail::view_impl<Sequence>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_REVERSED_HPP
