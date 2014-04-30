/*!
 * @file
 * Defines the @ref Integer datatype.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_INTEGER_HPP
#define BOOST_MPL11_INTEGER_HPP

#include <boost/mpl11/fwd/integer.hpp>

#include <boost/mpl11/bitwise.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/logical_or/strict_specialization.hpp>
#include <boost/mpl11/enumerable.hpp>
#include <boost/mpl11/group.hpp>
#include <boost/mpl11/integral_domain.hpp>
#include <boost/mpl11/logical.hpp>
#include <boost/mpl11/monoid.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/ring.hpp>


namespace boost { namespace mpl11 {
    namespace integral_detail {
        template <typename ...T>
        struct or_impl : true_ { };

        template <typename ...T>
        struct or_impl<integer_c<T, false>...> : false_ { };

        template <typename ...T>
        struct and_impl : false_ { };

        template <typename ...T>
        struct and_impl<integer_c<T, true>...> : true_ { };
    } // end namespace integral_detail

    template <typename T, T ...v>
    struct or_<integer_c<T, v>...>
        : detail::logical_or::strict_specialization<integer_c<T, v>...>
    { };

    template <typename T, T ...v>
    struct and_<integer_c<T, v>...>
        : bool_< // DeMorgan
            !detail::logical_or::strict_specialization<bool_<!v>...>::value
        >
    { };


    template <>
    struct Monoid<Integer> : instantiate<Monoid>::with<Integer> {
        template <typename x, typename y>
        using plus_impl = integer_c<
            decltype(x::value + y::value),
            x::value + y::value
        >;

        template <typename ...>
        using zero_impl = int_<0>;
    };

    template <>
    struct Group<Integer> : instantiate<Group>::with<Integer> {
        template <typename x, typename y>
        using minus_impl = integer_c<
            decltype(x::value - y::value),
            x::value - y::value
        >;

        template <typename x>
        using negate_impl = integer_c<
            decltype(-x::value),
            -x::value
        >;
    };

    template <>
    struct Ring<Integer> : instantiate<Ring>::with<Integer> {
        template <typename x, typename y>
        using mult_impl = integer_c<
            decltype(x::value * y::value),
            x::value * y::value
        >;

        template <typename ...>
        using one_impl = int_<1>;
    };

    template <>
    struct IntegralDomain<Integer>
        : instantiate<IntegralDomain>::with<Integer>
    {
        template <typename x, typename y>
        using div_impl = integer_c<
            decltype(x::value / y::value),
            x::value / y::value
        >;

        template <typename x, typename y>
        using mod_impl = integer_c<
            decltype(x::value % y::value),
            x::value % y::value
        >;
    };

    template <>
    struct Enumerable<Integer> : instantiate<Enumerable>::with<Integer> {
        template <typename x>
        using succ_impl = integer_c<
            decltype(x::value + 1),
            x::value + 1
        >;

        template <typename x>
        using pred_impl = integer_c<
            decltype(x::value - 1),
            x::value - 1
        >;
    };

    template <>
    struct Comparable<Integer> : instantiate<Comparable>::with<Integer> {
        template <typename x, typename y>
        using equal_impl = bool_<x::value == y::value>;

        template <typename x, typename y>
        using not_equal_impl = bool_<x::value != y::value>;
    };

    template <>
    struct Orderable<Integer> : instantiate<Orderable>::with<Integer> {
        template <typename x, typename y>
        using less_impl = bool_<(x::value < y::value)>;

        template <typename x, typename y>
        using less_equal_impl = bool_<(x::value <= y::value)>;

        template <typename x, typename y>
        using greater_impl = bool_<(x::value > y::value)>;

        template <typename x, typename y>
        using greater_equal_impl = bool_<(x::value >= y::value)>;

        template <typename x, typename y>
        using max_impl = if_c<(x::value < y::value), y, x>;

        template <typename x, typename y>
        using min_impl = if_c<(x::value < y::value), x, y>;
    };

    template <>
    struct Bitwise<Integer> : instantiate<Bitwise>::with<Integer> {
        template <typename x, typename y>
        using bitand_impl = integer_c<
            decltype(x::value & y::value),
            x::value & y::value
        >;

        template <typename x, typename y>
        using bitor_impl = integer_c<
            decltype(x::value | y::value),
            x::value | y::value
        >;

        template <typename x, typename y>
        using bitxor_impl = integer_c<
            decltype(x::value ^ y::value),
            x::value ^ y::value
        >;

        template <typename x, typename n>
        using shift_left_impl = integer_c<
            decltype(x::value << n::value),
            (x::value << n::value)
        >;

        template <typename x, typename n>
        using shift_right_impl = integer_c<
            decltype(x::value >> n::value),
            (x::value >> n::value)
        >;

        template <typename x>
        using compl_impl = integer_c<
            decltype(~x::value),
            ~x::value
        >;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGER_HPP
