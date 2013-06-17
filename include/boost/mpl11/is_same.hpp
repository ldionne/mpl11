/*!
 * @file
 * This file defines `boost::mpl11::is_same`.
 */

#ifndef BOOST_MPL11_IS_SAME_HPP
#define BOOST_MPL11_IS_SAME_HPP

#include <boost/mpl11/and.hpp>

#include <boost/type_traits/is_same.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename T0, typename T1, typename ...Tn>
struct is_same
    : and_<
        is_same<T0, T1>,
        is_same<T1, Tn...>
    >
{ };

template <typename A, typename B>
struct is_same<A, B>
    : boost::is_same<A, B>
{ };
}}}

#endif // !BOOST_MPL11_IS_SAME_HPP
