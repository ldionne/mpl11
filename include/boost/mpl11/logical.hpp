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
#include <boost/mpl11/detail/config.hpp>


namespace boost { namespace mpl11 {
    namespace logical_detail {
        template <bool current, bool done>
        struct and_impl {
            template <typename ...>
            using result = bool_<current>;
        };

        template <>
        struct and_impl<true, false> {
            template <typename x, typename ...xs>
            struct result
                : and_impl<(bool)x::type::value, sizeof...(xs) == 0>::
                  template result<xs...>
            { };
        };

        template <bool current, bool done>
        struct or_impl {
            template <typename ...>
            using result = bool_<current>;
        };

        template <>
        struct or_impl<false, false> {
            template <typename x, typename ...xs>
            struct result
                : or_impl<(bool)x::type::value, sizeof...(xs) == 0>::
                  template result<xs...>
            { };
        };

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
    } // end namespace logical_detail

    template <typename ...xs>
    struct and_
        : logical_detail::and_impl<true, false>::
          template result<true_, xs...>
    { };

    template <typename ...xs>
    struct or_
        : logical_detail::or_impl<false, false>::
          template result<false_, xs...>
    { };

    template <> struct and_<> : true_ { };
    template <> struct or_<>  : false_ { };

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
