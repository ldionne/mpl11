/*!
 * @file
 * Defines the @ref Integer datatype.
 */

#ifndef BOOST_MPL11_INTEGER_HPP
#define BOOST_MPL11_INTEGER_HPP

#include <boost/mpl11/fwd/integer.hpp>

#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/enumerable.hpp>
#include <boost/mpl11/group.hpp>
#include <boost/mpl11/integral_domain.hpp>
#include <boost/mpl11/logical.hpp>
#include <boost/mpl11/monoid.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/ring.hpp>


namespace boost { namespace mpl11 {
    namespace integral_c_detail {
        template <typename ...T>
        struct or_impl : true_ { };

        template <typename ...T>
        struct or_impl<integral_c<T, false>...> : false_ { };

        template <typename ...T>
        struct and_impl : false_ { };

        template <typename ...T>
        struct and_impl<integral_c<T, true>...> : true_ { };
    } // end namespace integral_c_detail

    template <typename T, T ...v>
    struct or_<integral_c<T, v>...>
        : integral_c_detail::or_impl<bool_<(bool)v>...>
    { };

    template <typename T, T ...v>
    struct and_<integral_c<T, v>...>
        : integral_c_detail::and_impl<bool_<(bool)v>...>
    { };


    template <>
    struct Monoid<Integer> {
        template <typename x, typename y>
        using plus_impl = integral_c<
            decltype(x::type::value + y::type::value),
            x::type::value + y::type::value
        >;

        template <typename ...>
        using zero_impl = int_<0>;
    };

    template <>
    struct Group<Integer> {
        template <typename x, typename y>
        using minus_impl = integral_c<
            decltype(x::type::value - y::type::value),
            x::type::value - y::type::value
        >;

        template <typename x>
        using negate_impl = integral_c<
            decltype(-x::type::value),
            -x::type::value
        >;
    };

    template <>
    struct Ring<Integer> {
        template <typename x, typename y>
        using mult_impl = integral_c<
            decltype(x::type::value * y::type::value),
            x::type::value * y::type::value
        >;

        template <typename ...>
        using one_impl = int_<1>;
    };

    template <>
    struct IntegralDomain<Integer> {
        template <typename x, typename y>
        using div_impl = integral_c<
            decltype(x::type::value / y::type::value),
            x::type::value / y::type::value
        >;

        template <typename x, typename y>
        using mod_impl = integral_c<
            decltype(x::type::value % y::type::value),
            x::type::value % y::type::value
        >;
    };

    template <>
    struct Enumerable<Integer> {
        template <typename x>
        using succ_impl = integral_c<
            decltype(x::type::value + 1),
            x::type::value + 1
        >;

        template <typename x>
        using pred_impl = integral_c<
            decltype(x::type::value - 1),
            x::type::value - 1
        >;
    };

    template <>
    struct Comparable<Integer> {
        template <typename x, typename y>
        using equal_impl = bool_<x::type::value == y::type::value>;

        template <typename x, typename y>
        using not_equal_impl = bool_<x::type::value != y::type::value>;
    };

    template <>
    struct Orderable<Integer> {
        template <typename x, typename y>
        using less_impl = bool_<(x::type::value < y::type::value)>;

        template <typename x, typename y>
        using less_equal_impl = bool_<(x::type::value <= y::type::value)>;

        template <typename x, typename y>
        using greater_impl = bool_<(x::type::value > y::type::value)>;

        template <typename x, typename y>
        using greater_equal_impl = bool_<(x::type::value >= y::type::value)>;

        template <typename x, typename y>
        using max_impl = if_c<(x::type::value < y::type::value), y, x>;

        template <typename x, typename y>
        using min_impl = if_c<(x::type::value < y::type::value), x, y>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGER_HPP
