/*!
 * @file
 * Defines the @ref Logical module.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_LOGICAL_HPP
#define BOOST_MPL11_LOGICAL_HPP

#include <boost/mpl11/fwd/logical.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/right_folds/variadic.hpp>


namespace boost { namespace mpl11 {
    namespace logical_detail {
        template <bool cond>
        struct if_impl;

        template <>
        struct if_impl<true> {
            template <typename Then, typename Else>
            using result = Then;
        };

        template <>
        struct if_impl<false> {
            template <typename Then, typename Else>
            using result = Else;
        };

        struct and2 {
            using type = and2;
            template <typename x, typename y>
            struct apply
                : bool_<
                    (bool)if_c<(bool)x::type::value, y, x>::type::value
                >
            { };
        };

        struct or2 {
            using type = or2;
            template <typename x, typename y>
            struct apply
                : bool_<
                    (bool)if_c<(bool)x::type::value, x, y>::type::value
                >
            { };
        };
    } // end namespace logical_detail

    template <typename ...xs>
    struct and_
        : detail::right_folds::variadic<logical_detail::and2, true_, xs...>
    { };

    template <typename ...xs>
    struct or_
        : detail::right_folds::variadic<logical_detail::or2, false_, xs...>
    { };

    template <typename x>
    struct not_
        : bool_<!x::type::value>
    { };

    template <typename Condition, typename Then, typename Else>
    struct if_ :
        logical_detail::if_impl<(bool)Condition::type::value>::
        template result<Then, Else>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LOGICAL_HPP
