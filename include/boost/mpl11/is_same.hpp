/*!
 * @file
 * Defines `boost::mpl11::is_same`.
 */

#ifndef BOOST_MPL11_IS_SAME_HPP
#define BOOST_MPL11_IS_SAME_HPP

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/bool.hpp>


namespace boost { namespace mpl11 {
    template <typename T0, typename T1, typename ...Tn>
    struct is_same
        : and_<
            is_same<T0, T1>,
            is_same<T1, Tn...>
        >
    { };

    template <typename T, typename U>
    struct is_same<T, U>
        : false_
    { };

    template <typename T>
    struct is_same<T, T>
        : true_
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IS_SAME_HPP
