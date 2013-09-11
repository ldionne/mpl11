/*!
 * @file
 * Defines `boost::mpl11::detail::is_same`.
 */

#ifndef BOOST_MPL11_DETAIL_IS_SAME_HPP
#define BOOST_MPL11_DETAIL_IS_SAME_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename T, typename U>
    struct is_same
        : identity<false_>
    { };

    template <typename T>
    struct is_same<T, T>
        : identity<true_>
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_IS_SAME_HPP
