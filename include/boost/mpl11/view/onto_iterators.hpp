/*!
 * @file
 * Defines `boost::mpl11::view::onto_iterators`.
 */

#ifndef BOOST_MPL11_VIEW_ONTO_ITERATORS_HPP
#define BOOST_MPL11_VIEW_ONTO_ITERATORS_HPP

#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next_fwd.hpp>
#include <boost/mpl11/intrinsic/prior_fwd.hpp>
#include <boost/mpl11/operator/equal_to_fwd.hpp>
#include <boost/mpl11/operator/less_fwd.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/onto_iterators_fwd.hpp>


namespace boost { namespace mpl11 {
//////////////////////////////////////////////////////////////////////////////
// Implementation of the iterator
//////////////////////////////////////////////////////////////////////////////
namespace onto_iterators_detail {
    template <typename Iterator>
    struct iterator;
}

template <typename Iterator>
struct dispatch<tag::next, onto_iterators_detail::iterator<Iterator>>
    : next<Iterator>
{ };

template <typename Iterator>
struct dispatch<tag::prior, onto_iterators_detail::iterator<Iterator>>
    : prior<Iterator>
{ };

template <typename Iterator>
struct dispatch<tag::deref, onto_iterators_detail::iterator<Iterator>>
    : identity<Iterator>
{ };

template <typename Iterator>
struct dispatch<tag::category_of, onto_iterators_detail::iterator<Iterator>>
    : category_of<Iterator>
{ };

template <typename It1, typename It2>
struct dispatch<tag::equal_to,
    onto_iterators_detail::iterator<It1>,
    onto_iterators_detail::iterator<It2>
>
    : equal_to<It1, It2>
{ };

template <typename It1, typename It2>
struct dispatch<tag::less,
    onto_iterators_detail::iterator<It1>,
    onto_iterators_detail::iterator<It2>
>
    : less<It1, It2>
{ };


//////////////////////////////////////////////////////////////////////////////
// Implementation of the view
//////////////////////////////////////////////////////////////////////////////
namespace onto_iterators_detail {
    template <typename Sequence>
    using view_impl = view::bounded_by<
        iterator<typename begin<Sequence>::type>,
        iterator<typename end<Sequence>::type>
    >;
}

template <typename Sequence>
struct dispatch<tag::begin, view::onto_iterators<Sequence>>
    : begin<onto_iterators_detail::view_impl<Sequence>>
{ };

template <typename Sequence>
struct dispatch<tag::end, view::onto_iterators<Sequence>>
    : end<onto_iterators_detail::view_impl<Sequence>>
{ };

template <typename Sequence>
struct dispatch<tag::category_of, view::onto_iterators<Sequence>>
    : category_of<onto_iterators_detail::view_impl<Sequence>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_ONTO_ITERATORS_HPP
