/*!
 * @file
 * Defines `boost::mpl11::min`.
 */

#ifndef BOOST_MPL11_ALGORITHM_MIN_HPP
#define BOOST_MPL11_ALGORITHM_MIN_HPP

#include <boost/mpl11/algorithm/min_fwd.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/operator/less.hpp>


namespace boost { namespace mpl11 {
    template <typename T1, typename T2, typename ...Tn>
    struct dispatch<tag::default_<tag::min>, T1, T2, Tn...>
        : min<T1, typename min<T2, Tn...>::type>
    { };

    template <typename T1, typename T2>
    struct dispatch<tag::default_<tag::min>, T1, T2>
        : if_<less<T1, T2>, T1, T2>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_MIN_HPP
