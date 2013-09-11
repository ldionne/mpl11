/*!
 * @file
 * Defines the default implementation of `boost::mpl11::greater`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_GREATER_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_GREATER_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/operator/and.hpp>
#include <boost/mpl11/operator/greater.hpp>
#include <boost/mpl11/operator/less.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    template <typename T1, typename T2, typename ...Tn>
    struct dispatch<detail::default_<tag::greater>, T1, T2, Tn...>
        : and_<
            greater<T1, T2>,
            greater<T2, Tn...>
        >
    { };

    template <typename T1, typename T2>
    struct dispatch<detail::default_<tag::greater>, T1, T2>
        : less<T2, T1>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_GREATER_HPP
