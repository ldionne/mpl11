/*!
 * @file
 * Defines `boost::mpl11::Logical`.
 */

#ifndef BOOST_MPL11_LOGICAL_HPP
#define BOOST_MPL11_LOGICAL_HPP

#include <boost/mpl11/fwd/logical.hpp>

#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    // IMPORTANT:
    // Do not use `if_` instead of `detail::conditional` here.
    // `if_` depends on `integral_c`, which in turns depends on `Logical`.
    // Also, using `detail::conditional` is more efficient.

    template <typename A, typename B>
    struct Logical::and_impl
        : detail::conditional<not_<A>::value, A, B>::type
    { };

    template <typename A, typename B>
    struct Logical::or_impl
        : detail::conditional<not_<A>::value, B, A>::type
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LOGICAL_HPP
