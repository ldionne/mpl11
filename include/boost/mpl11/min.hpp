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
    template <typename T1, typename T2, typename ...Tn>
    struct min
        : min<T1, typename min<T2, Tn...>::type>
    { };

    template <typename T1, typename T2>
    struct min<T1, T2>
        : if_<less<T1, T2>, T1, T2>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_MIN_HPP
