/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::min`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_MIN_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_MIN_HPP

#include <boost/mpl11/algorithm/min.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/less.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
template <typename T1, typename T2, typename ...Tn>
struct dispatch<detail::default_<tag::min>, T1, T2, Tn...>
    : algorithm::min<T1, typename algorithm::min<T2, Tn...>::type>
{ };

template <typename T1, typename T2>
struct dispatch<detail::default_<tag::min>, T1, T2>
    : if_<intrinsic::less<T1, T2>, T1, T2>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_MIN_HPP
