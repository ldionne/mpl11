/*!
 * @file
 * Defines `boost::mpl11::less`.
 */

#ifndef BOOST_MPL11_LESS_HPP
#define BOOST_MPL11_LESS_HPP

#include <boost/mpl11/fwd/less.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/detail/dual_dispatch.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
template <typename T1, typename T2, typename ...Tn>
struct dispatch<tag::less, T1, T2, Tn...>
    : and_<
        less<T1, T2>,
        less<T2, Tn...>
    >
{ };

template <typename T1, typename T2>
struct dispatch<tag::less, T1, T2>
    : detail::dual_dispatch<tag::less, T1, T2>::template apply<T1, T2>
{ };

template <>
struct dispatch<
    tag::dual<tag::less>,
    category::integral_constant,
    category::integral_constant
> {
    template <typename I, typename J>
    struct apply
        : identity<
            bool_<I::value < J::value>
        >
    { };
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LESS_HPP
