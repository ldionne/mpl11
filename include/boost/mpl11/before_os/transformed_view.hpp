/*!
 * @file
 * Defines `boost::mpl11::transformed_view`.
 */

#ifndef BOOST_MPL11_TRANSFORMED_VIEW_HPP
#define BOOST_MPL11_TRANSFORMED_VIEW_HPP

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/equal_to.hpp>
#include <boost/mpl11/fwd/less.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/fwd/prior.hpp>
#include <boost/mpl11/fwd/transformed_view.hpp>
#include <boost/mpl11/iterator_range.hpp>


namespace boost { namespace mpl11 {
//////////////////////////////////////////////////////////////////////////////
// Implementation of the iterator
//////////////////////////////////////////////////////////////////////////////
namespace transformed_detail {
    template <typename Iterator, typename F>
    struct iterator;
}

template <typename Iterator, typename F>
struct dispatch<tag::next, transformed_detail::iterator<Iterator, F>>
    : next<Iterator>
{ };

template <typename Iterator, typename F>
struct dispatch<tag::prior, transformed_detail::iterator<Iterator, F>>
    : prior<Iterator>
{ };

template <typename Iterator, typename F>
struct dispatch<tag::deref, transformed_detail::iterator<Iterator, F>>
    : apply<F, typename deref<Iterator>::type>
{ };

template <typename Iterator, typename F>
struct dispatch<tag::category_of, transformed_detail::iterator<Iterator, F>>
    : category_of<Iterator>
{ };

template <typename It1, typename It2, typename F>
struct dispatch<tag::equal_to,
    transformed_detail::iterator<It1, F>,
    transformed_detail::iterator<It2, F>
>
    : equal_to<It1, It2>
{ };

template <typename It1, typename It2, typename F>
struct dispatch<tag::less,
    transformed_detail::iterator<It1, F>,
    transformed_detail::iterator<It2, F>
>
    : less<It1, It2>
{ };


//////////////////////////////////////////////////////////////////////////////
// Implementation of the view
//////////////////////////////////////////////////////////////////////////////
namespace transformed_detail {
    template <typename Sequence, typename F>
    using view_impl = iterator_range<
        iterator<typename begin<Sequence>::type, F>,
        iterator<typename end<Sequence>::type, F>
    >;
}

template <typename Sequence, typename F>
struct dispatch<tag::begin, transformed_view<Sequence, F>>
    : begin<transformed_detail::view_impl<Sequence, F>>
{ };

template <typename Sequence, typename F>
struct dispatch<tag::end, transformed_view<Sequence, F>>
    : end<transformed_detail::view_impl<Sequence, F>>
{ };

template <typename Sequence, typename F>
struct dispatch<tag::category_of, transformed_view<Sequence, F>>
    : category_of<transformed_detail::view_impl<Sequence, F>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TRANSFORMED_VIEW_HPP
