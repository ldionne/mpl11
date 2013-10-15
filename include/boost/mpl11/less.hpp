/*!
 * @file
 * Defines `boost::mpl11::less`.
 */

#ifndef BOOST_MPL11_LESS_HPP
#define BOOST_MPL11_LESS_HPP

#include <boost/mpl11/fwd/less.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/equal_to.hpp>
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

template <typename I, typename J>
struct dispatch<tag::less, I, J>
    : apply_wrap<
        dispatch<tag::by_category<tag::less>, typename category_of<I>::type>,
        I, J
    >
{
    static_assert(equal_to<
                    typename category_of<I>::type,
                    typename category_of<J>::type
                  >::type::value,
    "Trying to less-than compare two types with different categories.");
};

template <>
struct dispatch<tag::by_category<tag::less>, category::integral_constant> {
    template <typename I, typename J>
    struct apply
        : identity<
            bool_<I::value < J::value>
        >
    { };
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LESS_HPP
