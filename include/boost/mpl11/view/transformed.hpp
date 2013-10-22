/*!
 * @file
 * Defines `boost::mpl11::view::transformed`.
 */

#ifndef BOOST_MPL11_VIEW_TRANSFORMED_HPP
#define BOOST_MPL11_VIEW_TRANSFORMED_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/deref_fwd.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next_fwd.hpp>
#include <boost/mpl11/intrinsic/prior_fwd.hpp>
#include <boost/mpl11/operator/equal_to_fwd.hpp>
#include <boost/mpl11/operator/less_fwd.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/transformed_fwd.hpp>


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
    using view_impl = view::bounded_by<
        iterator<typename begin<Sequence>::type, F>,
        iterator<typename end<Sequence>::type, F>
    >;
}

template <typename Sequence, typename F>
struct dispatch<tag::begin, view::transformed<Sequence, F>>
    : begin<transformed_detail::view_impl<Sequence, F>>
{ };

template <typename Sequence, typename F>
struct dispatch<tag::end, view::transformed<Sequence, F>>
    : end<transformed_detail::view_impl<Sequence, F>>
{ };

template <typename Sequence, typename F>
struct dispatch<tag::category_of, view::transformed<Sequence, F>>
    : category_of<transformed_detail::view_impl<Sequence, F>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_TRANSFORMED_HPP
