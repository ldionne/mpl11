/*!
 * @file
 * Defines `boost::mpl11::view::zipped`.
 */

#ifndef BOOST_MPL11_VIEW_ZIPPED_HPP
#define BOOST_MPL11_VIEW_ZIPPED_HPP

#include <boost/mpl11/algorithm/min.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/deref_fwd.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next_fwd.hpp>
#include <boost/mpl11/intrinsic/prior_fwd.hpp>
#include <boost/mpl11/intrinsic/size.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/sliced.hpp>
#include <boost/mpl11/view/zipped_fwd.hpp>


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
        container::vector<typename deref<Iterators>::type...>
    >
{ };

template <typename ...Iterators>
struct dispatch<tag::category_of, zipped_detail::zip_iterator<Iterators...>>
    : algorithm::min<typename category_of<Iterators>::type...>
{ };


//////////////////////////////////////////////////////////////////////////////
// Implementation of the view
//////////////////////////////////////////////////////////////////////////////
namespace zipped_detail {
    template <typename ...Sequences>
    using once_truncated = view::bounded_by<
        zip_iterator<typename begin<Sequences>::type...>,
        zip_iterator<typename end<Sequences>::type...>
    >;

    template <typename ...Sequences>
    using view_impl = once_truncated<
        view::sliced<
            Sequences,
            ulong<0>,
            typename size<view::zipped<Sequences...>>::type
        >...
    >;
} // end namespace zipped_detail

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::size, view::zipped<S1, S2, Sn...>>
    : algorithm::min<
        typename size<S1>::type,
        typename size<S2>::type,
        typename size<Sn>::type...
    >
{ };

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::begin, view::zipped<S1, S2, Sn...>>
    : begin<zipped_detail::view_impl<S1, S2, Sn...>>
{ };

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::end, view::zipped<S1, S2, Sn...>>
    : end<zipped_detail::view_impl<S1, S2, Sn...>>
{ };

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::category_of, view::zipped<S1, S2, Sn...>>
    : category_of<zipped_detail::view_impl<S1, S2, Sn...>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_ZIPPED_HPP
