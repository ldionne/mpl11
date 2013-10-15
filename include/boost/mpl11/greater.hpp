/*!
 * @file
 * Defines `boost::mpl11::greater`.
 */

#ifndef BOOST_MPL11_GREATER_HPP
#define BOOST_MPL11_GREATER_HPP

#include <boost/mpl11/fwd/greater.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/less.hpp>


namespace boost { namespace mpl11 {
    template <typename T1, typename T2, typename ...Tn>
    struct dispatch<tag::greater, T1, T2, Tn...>
        : and_<
            greater<T1, T2>,
            greater<T2, Tn...>
        >
    { };

    template <typename T1, typename T2>
    struct dispatch<tag::greater, T1, T2>
        : less<T2, T1>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_GREATER_HPP
