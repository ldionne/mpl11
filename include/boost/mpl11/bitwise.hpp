/*!
 * @file
 * Defines the @ref Bitwise typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_BITWISE_HPP
#define BOOST_MPL11_BITWISE_HPP

#include <boost/mpl11/fwd/bitwise.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/config.hpp>
#include <boost/mpl11/detail/strict_variadic_foldl.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/integer.hpp> // required by fwd/bitwise.hpp


namespace boost { namespace mpl11 {
    template <typename Left, typename Right, typename>
    struct Bitwise : false_ { };

    template <typename x1, typename x2, typename ...xn>
    struct bitand_
        : detail::strict_variadic_foldl<lift<bitand_>, x1, x2, xn...>
    { };

    template <typename x, typename y>
    struct bitand_<x, y> :
        Bitwise<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template bitand_impl<typename x::type, typename y::type>
    { };


    template <typename x1, typename x2, typename ...xn>
    struct bitor_
        : detail::strict_variadic_foldl<lift<bitor_>, x1, x2, xn...>
    { };

    template <typename x, typename y>
    struct bitor_<x, y> :
        Bitwise<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template bitor_impl<typename x::type, typename y::type>
    { };


    template <typename x1, typename x2, typename ...xn>
    struct bitxor
        : detail::strict_variadic_foldl<lift<bitxor>, x1, x2, xn...>
    { };

    template <typename x, typename y>
    struct bitxor<x, y> :
        Bitwise<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template bitxor_impl<typename x::type, typename y::type>
    { };

    namespace checks {
        template <typename x, typename n>
        struct shift_left_checks {
            static_assert(n::type::value >= 0,
            "Invalid usage of `shift_left` with a negative shift.");
        };

        template <typename x, typename n>
        struct shift_right_checks {
            static_assert(n::type::value >= 0,
            "Invalid usage of `shift_right` with a negative shift.");
        };
    }

    namespace unchecked {
        template <typename x, typename n>
        struct shift_left :
            Bitwise<typename datatype<typename x::type>::type>::
            template shift_left_impl<typename x::type, n>
        { };

        template <typename x, typename n>
        struct shift_right :
            Bitwise<typename datatype<typename x::type>::type>::
            template shift_right_impl<typename x::type, n>
        { };
    }

    template <typename x>
    struct compl_ :
        Bitwise<typename datatype<typename x::type>::type>::
        template compl_impl<typename x::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BITWISE_HPP
