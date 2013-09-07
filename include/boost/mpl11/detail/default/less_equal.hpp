/*!
 * @file
 * Defines the default implementation of `boost::mpl11::intrinsic::less_equal`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_LESS_EQUAL_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_LESS_EQUAL_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/and.hpp>
#include <boost/mpl11/intrinsic/less.hpp>
#include <boost/mpl11/intrinsic/less_equal.hpp>
#include <boost/mpl11/intrinsic/not.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename T1, typename T2, typename ...Tn>
struct dispatch<detail::default_<tag::less_equal>, T1, T2, Tn...>
    : intrinsic::and_<
        intrinsic::less_equal<T1, T2>,
        intrinsic::less_equal<T2, Tn...>
    >
{ };

template <typename T1, typename T2>
struct dispatch<detail::default_<tag::less_equal>, T1, T2>
    : intrinsic::not_<intrinsic::less<T2, T1>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_LESS_EQUAL_HPP
