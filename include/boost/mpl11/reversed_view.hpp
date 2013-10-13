/*!
 * @file
 * Defines `boost::mpl11::reversed_view`.
 */

#ifndef BOOST_MPL11_REVERSED_VIEW_HPP
#define BOOST_MPL11_REVERSED_VIEW_HPP

#include <boost/mpl11/fwd/reversed_view.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/equal_to.hpp>
#include <boost/mpl11/fwd/less.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/prior.hpp>


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
    using view_impl = iterator_range<
        iterator<typename end<Sequence>::type>,
        iterator<typename begin<Sequence>::type>
    >;
} // end namespace reversed_detail

template <typename Sequence>
struct dispatch<tag::begin, reversed_view<Sequence>>
    : begin<reversed_detail::view_impl<Sequence>>
{ };

template <typename Sequence>
struct dispatch<tag::end, reversed_view<Sequence>>
    : end<reversed_detail::view_impl<Sequence>>
{ };

template <typename Sequence>
struct dispatch<tag::category_of, reversed_view<Sequence>>
    : category_of<reversed_detail::view_impl<Sequence>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_REVERSED_VIEW_HPP
