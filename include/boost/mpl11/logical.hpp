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
    struct Logical {
        //! This operation must be provided by the user.
        template <typename L>
        struct not_impl;

        // IMPORTANT:
        // Do not use `if_` instead of `detail::conditional` here.
        // `if_` depends on `integral_c`, which in turns depends on `Logical`.
        // Also, using `detail::conditional` is more efficient.

        /*!
         * Returns `A::type` if `not_<A>::value` is `true` and
         * `B::type` otherwise.
         */
        template <typename A, typename B>
        struct and_impl
            : detail::conditional<not_<A>::value, A, B>::type
        { };

        /*!
         * Returns `B::type` if `not_<A>::value` is `true` and
         * `A::type` otherwise.
         */
        template <typename A, typename B>
        struct or_impl
            : detail::conditional<not_<A>::value, B, A>::type
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LOGICAL_HPP
