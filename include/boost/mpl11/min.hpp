/*!
 * @file
 * Defines `boost::mpl11::min`.
 */

#ifndef BOOST_MPL11_MIN_HPP
#define BOOST_MPL11_MIN_HPP

#include <boost/mpl11/fwd/min.hpp>

#include <boost/mpl11/if.hpp>
#include <boost/mpl11/less.hpp>


namespace boost { namespace mpl11 {
    template <typename T1, typename T2, typename T3, typename ...Tn>
    struct min<T1, T2, T3, Tn...>
        : min<T1, min_t<T2, T3, Tn...>>
    { };

    template <typename T1, typename T2>
    struct min<T1, T2>
        : if_<less<T1, T2>, T1, T2>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_MIN_HPP
