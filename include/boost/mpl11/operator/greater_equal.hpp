/*!
 * @file
 * Defines `boost::mpl11::greater_equal`.
 */

#ifndef BOOST_MPL11_OPERATOR_GREATER_EQUAL_HPP
#define BOOST_MPL11_OPERATOR_GREATER_EQUAL_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/operator/and.hpp>
#include <boost/mpl11/operator/greater_equal_fwd.hpp>
#include <boost/mpl11/operator/less.hpp>
#include <boost/mpl11/operator/not.hpp>


namespace boost { namespace mpl11 {
    template <typename T1, typename T2, typename ...Tn>
    struct dispatch<tag::default_<tag::greater_equal>, T1, T2, Tn...>
        : and_<
            greater_equal<T1, T2>,
            greater_equal<T2, Tn...>
        >
    { };

    template <typename T1, typename T2>
    struct dispatch<tag::default_<tag::greater_equal>, T1, T2>
        : not_<less<T1, T2>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_OPERATOR_GREATER_EQUAL_HPP
