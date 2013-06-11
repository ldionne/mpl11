/*!
 * @file
 * This file defines `boost::mpl11::and_`.
 */

#ifndef BOOST_MPL11_AND_HPP
#define BOOST_MPL11_AND_HPP

#include <mpl11/bool.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace and_detail {
    template <bool F1, typename ...Fn>
    struct and_impl;

    template <bool F1>
    struct and_impl<F1> : bool_<F1> { };

    template <typename F2, typename ...Fn>
    struct and_impl<false, F2, Fn...> : false_ { };

    template <typename F2, typename ...Fn>
    struct and_impl<true, F2, Fn...>
        : and_impl<F2::type::value, Fn...>
    { };
} // end namespace and_detail

template <typename F1, typename F2, typename ...Fn>
struct and_
    : and_detail::and_impl<F1::type::value, F2, Fn...>
{ };
}}}

#endif // !BOOST_MPL11_AND_HPP
