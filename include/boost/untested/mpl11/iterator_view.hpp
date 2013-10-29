/*!
 * @file
 * Defines `boost::mpl11::iterator_view`.
 */

#ifndef BOOST_MPL11_ITERATOR_VIEW_HPP
#define BOOST_MPL11_ITERATOR_VIEW_HPP

#include <boost/mpl11/fwd/iterator_view.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/fwd/equal_to.hpp>
#include <boost/mpl11/fwd/less.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/fwd/prior.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/iterator_range.hpp>


namespace boost { namespace mpl11 {
//////////////////////////////////////////////////////////////////////////////
// Implementation of the iterator
//////////////////////////////////////////////////////////////////////////////
namespace iterator_view_detail {
    template <typename Iterator>
    struct iterator;
}

template <typename Iterator>
struct dispatch<tag::next, iterator_view_detail::iterator<Iterator>>
    : next<Iterator>
{ };

template <typename Iterator>
struct dispatch<tag::prior, iterator_view_detail::iterator<Iterator>>
    : prior<Iterator>
{ };

template <typename Iterator>
struct dispatch<tag::deref, iterator_view_detail::iterator<Iterator>>
    : identity<Iterator>
{ };

template <typename Iterator>
struct dispatch<tag::category_of, iterator_view_detail::iterator<Iterator>>
    : category_of<Iterator>
{ };

template <typename It1, typename It2>
struct dispatch<tag::equal_to,
    iterator_view_detail::iterator<It1>,
    iterator_view_detail::iterator<It2>
>
    : equal_to<It1, It2>
{ };

template <typename It1, typename It2>
struct dispatch<tag::less,
    iterator_view_detail::iterator<It1>,
    iterator_view_detail::iterator<It2>
>
    : less<It1, It2>
{ };


//////////////////////////////////////////////////////////////////////////////
// Implementation of the view
//////////////////////////////////////////////////////////////////////////////
namespace iterator_view_detail {
    template <typename Sequence>
    using view_impl = iterator_range<
        iterator<typename begin<Sequence>::type>,
        iterator<typename end<Sequence>::type>
    >;
}

template <typename Sequence>
struct dispatch<tag::begin, iterator_view<Sequence>>
    : begin<iterator_view_detail::view_impl<Sequence>>
{ };

template <typename Sequence>
struct dispatch<tag::end, iterator_view<Sequence>>
    : end<iterator_view_detail::view_impl<Sequence>>
{ };

template <typename Sequence>
struct dispatch<tag::category_of, iterator_view<Sequence>>
    : category_of<iterator_view_detail::view_impl<Sequence>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERATOR_VIEW_HPP
