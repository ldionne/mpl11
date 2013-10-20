/*!
 * @file
 * Defines `boost::mpl11::max`.
 */

#ifndef BOOST_MPL11_MAX_HPP
#define BOOST_MPL11_MAX_HPP

#include <boost/mpl11/fwd/max.hpp>

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/less.hpp>


namespace boost { namespace mpl11 {
    template <typename T1, typename T2, typename ...Tn>
    struct dispatch<tag::max, T1, T2, Tn...>
        : max<T1, typename max<T2, Tn...>::type>
    { };

    template <typename T1, typename T2>
    struct dispatch<tag::max, T1, T2>
        : if_<less<T1, T2>, T2, T1>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_MAX_HPP
