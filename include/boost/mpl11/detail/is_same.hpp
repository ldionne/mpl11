/*!
 * @file
 * Defines `boost::mpl11::detail::is_same`.
 */

#ifndef BOOST_MPL11_DETAIL_IS_SAME_HPP
#define BOOST_MPL11_DETAIL_IS_SAME_HPP

#include <boost/mpl11/bool.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename T0, typename T1, typename ...Tn>
    struct is_same
        : bool_<is_same<T0, T1>::value && is_same<T1, Tn...>::value>
    { };

    template <typename T, typename U>
    struct is_same<T, U>
        : false_
    { };

    template <typename T>
    struct is_same<T, T>
        : true_
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_IS_SAME_HPP
