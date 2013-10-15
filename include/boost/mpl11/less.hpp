/*!
 * @file
 * Defines `boost::mpl11::less`.
 */

#ifndef BOOST_MPL11_LESS_HPP
#define BOOST_MPL11_LESS_HPP

#include <boost/mpl11/fwd/less.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/detail/best_category_for.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
template <typename T1, typename T2, typename ...Tn>
struct dispatch<tag::default_<tag::less>, T1, T2, Tn...>
    : and_<
        less<T1, T2>,
        less<T2, Tn...>
    >
{ };

namespace less_detail {
    template <typename Category1, typename T1, typename Category2, typename T2>
    struct less_impl;

    template <typename T1, typename T2>
    struct less_impl<category::integral_constant, T1,
                     category::integral_constant, T2>
        : identity<
            bool_<T1::value < T2::value>
        >
    { };
} // end namespace less_detail

template <typename T1, typename T2>
struct dispatch<tag::default_<tag::less>, T1, T2>
    : less_detail::less_impl<
        typename detail::best_category_for<
            T1, category::integral_constant
        >::type, T1,
        typename detail::best_category_for<
            T2, category::integral_constant
        >::type, T2
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LESS_HPP
