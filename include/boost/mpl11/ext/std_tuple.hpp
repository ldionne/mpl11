/*!
 * @file
 * Defines typeclass instantiations for `std::tuple`.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_EXT_STD_TUPLE_HPP
#define BOOST_MPL11_EXT_STD_TUPLE_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/fwd/foldable.hpp>
#include <boost/mpl11/fwd/list.hpp>
#include <boost/mpl11/iterable.hpp>

#include <tuple>


namespace boost { namespace mpl11 {
    struct StdTuple;

    template <typename ...xs>
    struct datatype<std::tuple<xs...>> {
        using type = StdTuple;
    };

    template <>
    struct cast</* from */ StdTuple, /* to */ List> {
        using type = cast;

        template <typename>
        struct apply;

        template <typename ...xs>
        struct apply<std::tuple<xs...>> {
            using type = list<box<xs>...>;
        };
    };

    template <>
    struct cast</* from */ List, /* to */ StdTuple> {
        using type = cast;

        template <typename>
        struct apply;

        template <typename ...xs>
        struct apply<list<xs...>> {
            using type = std::tuple<typename xs::type...>;
        };

        template <typename x, typename xs>
        struct apply<cons<x, xs>>
            : apply<typename unpack<into<list>, cons<x, xs>>::type>
        { };
    };

    template <>
    struct Iterable<StdTuple> : instantiate<Iterable>::with<StdTuple> {
        template <typename>
        struct head_impl;

        template <typename x, typename ...xs>
        struct head_impl<std::tuple<x, xs...>> {
            using type = x;
        };


        template <typename>
        struct tail_impl;

        template <typename x, typename ...xs>
        struct tail_impl<std::tuple<x, xs...>> {
            using type = std::tuple<xs...>;
        };


        template <typename>
        struct is_empty_impl;

        template <typename ...xs>
        struct is_empty_impl<std::tuple<xs...>>
            : bool_<sizeof...(xs) == 0>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EXT_STD_TUPLE_HPP
