/*!
 * @file
 * Defines `boost::mpl11::zipped_view`.
 */

#ifndef BOOST_MPL11_ZIPPED_VIEW_HPP
#define BOOST_MPL11_ZIPPED_VIEW_HPP

#include <boost/mpl11/fwd/zipped_view.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/fwd/prior.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/min.hpp>
#include <boost/mpl11/size.hpp>
#include <boost/mpl11/sliced_view.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
//////////////////////////////////////////////////////////////////////////////
// Implementation of the iterator
//////////////////////////////////////////////////////////////////////////////
namespace zipped_detail {
    template <typename ...Iterators>
    struct zip_iterator;
}

template <typename ...Iterators>
struct dispatch<tag::next, zipped_detail::zip_iterator<Iterators...>>
    : identity<
        zipped_detail::zip_iterator<typename next<Iterators>::type...>
    >
{ };

template <typename ...Iterators>
struct dispatch<tag::prior, zipped_detail::zip_iterator<Iterators...>>
    : identity<
        zipped_detail::zip_iterator<typename prior<Iterators>::type...>
    >
{ };

template <typename ...Iterators>
struct dispatch<tag::deref, zipped_detail::zip_iterator<Iterators...>>
    : identity<
        vector<typename deref<Iterators>::type...>
    >
{ };

template <typename ...Iterators>
struct dispatch<tag::category_of, zipped_detail::zip_iterator<Iterators...>>
    : min<typename category_of<Iterators>::type...>
{ };


//////////////////////////////////////////////////////////////////////////////
// Implementation of the view
//////////////////////////////////////////////////////////////////////////////
namespace zipped_detail {
    template <typename ...Sequences>
    using once_truncated = iterator_range<
        zip_iterator<typename begin<Sequences>::type...>,
        zip_iterator<typename end<Sequences>::type...>
    >;

    template <typename ...Sequences>
    using view_impl = once_truncated<
        sliced_view<
            Sequences,
            ulong<0>,
            typename size<zipped_view<Sequences...>>::type
        >...
    >;
} // end namespace zipped_detail

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::size, zipped_view<S1, S2, Sn...>>
    : min<
        typename size<S1>::type,
        typename size<S2>::type,
        typename size<Sn>::type...
    >
{ };

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::begin, zipped_view<S1, S2, Sn...>>
    : begin<zipped_detail::view_impl<S1, S2, Sn...>>
{ };

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::end, zipped_view<S1, S2, Sn...>>
    : end<zipped_detail::view_impl<S1, S2, Sn...>>
{ };

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::category_of, zipped_view<S1, S2, Sn...>>
    : category_of<zipped_detail::view_impl<S1, S2, Sn...>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ZIPPED_VIEW_HPP
