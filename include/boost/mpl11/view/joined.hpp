/*!
 * @file
 * Defines `boost::mpl11::view::joined`.
 */

#ifndef BOOST_MPL11_VIEW_JOINED_HPP
#define BOOST_MPL11_VIEW_JOINED_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/category_of_fwd.hpp>
#include <boost/mpl11/intrinsic/deref_fwd.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next_fwd.hpp>
#include <boost/mpl11/operator/equal_to.hpp>
#include <boost/mpl11/view/bounded_by.hpp>
#include <boost/mpl11/view/joined_fwd.hpp>


namespace boost { namespace mpl11 {
//////////////////////////////////////////////////////////////////////////////
// Implementation of the iterator
//////////////////////////////////////////////////////////////////////////////
namespace joined_detail {
    template <typename First1, typename Last1, typename First2>
    struct joined_iterator;

    template <typename F1, typename L1, typename F2,
              bool = equal_to<F1, L1>::type::value>
    struct next_impl
        : identity<
            joined_iterator<typename next<F1>::type, L1, F2>
        >
    { };

    template <typename F1, typename L1, typename F2>
    struct next_impl<F1, L1, F2, true>
        : identity<
            joined_iterator<F1, L1, typename next<F2>::type>
        >
    { };

    template <typename F1, typename L1, typename F2,
              bool = equal_to<F1, L1>::type::value>
    struct deref_impl
        : deref<F1>
    { };

    template <typename F1, typename L1, typename F2>
    struct deref_impl<F1, L1, F2, true>
        : deref<F2>
    { };
} // end namespace joined_detail

template <typename F1, typename L1, typename F2>
struct dispatch<tag::next, joined_detail::joined_iterator<F1, L1, F2>>
    : joined_detail::next_impl<F1, L1, F2>
{ };

template <typename F1, typename L1, typename F2>
struct dispatch<tag::deref, joined_detail::joined_iterator<F1, L1, F2>>
    : joined_detail::deref_impl<F1, L1, F2>
{ };

template <typename F1, typename L1, typename F2>
struct dispatch<tag::category_of, joined_detail::joined_iterator<F1, L1, F2>>
    : identity<category::forward_iterator>
{ };


//////////////////////////////////////////////////////////////////////////////
// Implementation of the view
//////////////////////////////////////////////////////////////////////////////
namespace joined_detail {
    template <typename S1, typename S2>
    using view_impl = view::bounded_by<
        joined_iterator<
            typename begin<S1>::type,
            typename end<S1>::type,
            typename begin<S2>::type
        >,
        joined_iterator<
            typename end<S1>::type,
            typename end<S1>::type,
            typename end<S2>::type
        >
    >;
} // end namespace joined_detail

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::begin, view::joined<S1, S2, Sn...>>
    : begin<view::joined<S1, view::joined<S2, Sn...>>>
{ };

template <typename S1, typename S2>
struct dispatch<tag::begin, view::joined<S1, S2>>
    : begin<joined_detail::view_impl<S1, S2>>
{ };

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::end, view::joined<S1, S2, Sn...>>
    : end<view::joined<S1, view::joined<S2, Sn...>>>
{ };

template <typename S1, typename S2>
struct dispatch<tag::end, view::joined<S1, S2>>
    : end<joined_detail::view_impl<S1, S2>>
{ };

template <typename S1, typename S2, typename ...Sn>
struct dispatch<tag::category_of, view::joined<S1, S2, Sn...>>
    : identity<category::forward_sequence>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_VIEW_JOINED_HPP
