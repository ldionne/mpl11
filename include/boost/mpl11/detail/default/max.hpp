/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::max`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_MAX_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_MAX_HPP

#include <boost/mpl11/algorithm/max.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/less.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename T1, typename T2, typename ...Tn>
struct dispatch<detail::default_<tag::max>, T1, T2, Tn...>
    : algorithm::max<T1, typename algorithm::max<T2, Tn...>::type>
{ };

template <typename T1, typename T2>
struct dispatch<detail::default_<tag::max>, T1, T2>
    : if_<intrinsic::less<T1, T2>, T2, T1>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_MAX_HPP
