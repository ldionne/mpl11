/*!
 * @file
 * Defines the @ref Bool datatype.
 */

#ifndef BOOST_MPL11_BOOL_HPP
#define BOOST_MPL11_BOOL_HPP

#include <boost/mpl11/fwd/bool.hpp>

#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/enumerable.hpp>
#include <boost/mpl11/orderable.hpp>


namespace boost { namespace mpl11 {
    template <bool b>
    struct bool_ {
        using value_type = bool;
        static constexpr value_type value = b;
        constexpr operator value_type() const { return value; }
        constexpr value_type operator()() const { return value; }
        using type = bool_;
        using mpl_datatype = Bool;
    };

    template <bool ...v>
    struct or_<bool_<v>...>
        : integral_detail::or_impl<bool_<(bool)v>...>
    { };

    template <bool ...v>
    struct and_<bool_<v>...>
        : integral_detail::and_impl<bool_<(bool)v>...>
    { };

    template <>
    struct Enumerable<Bool> {
        template <typename x>
        using succ_impl = bool_<x::type::value + 1>;

        template <typename x>
        using pred_impl = bool_<x::type::value - 1>;
    };

    template <>
    struct Comparable<Bool> {
        template <typename x, typename y>
        using equal_impl = bool_<x::type::value == y::type::value>;

        template <typename x, typename y>
        using not_equal_impl = bool_<x::type::value != y::type::value>;
    };

    template <>
    struct Orderable<Bool> {
        template <typename x, typename y>
        using less_impl = bool_<(x::type::value < y::type::value)>;

        template <typename x, typename y>
        using less_equal_impl = bool_<(x::type::value <= y::type::value)>;

        template <typename x, typename y>
        using greater_impl = bool_<(x::type::value > y::type::value)>;

        template <typename x, typename y>
        using greater_equal_impl = bool_<(x::type::value >= y::type::value)>;

        template <typename x, typename y>
        using max_impl = bool_<x::type::value || y::type::value>;

        template <typename x, typename y>
        using min_impl = bool_<x::type::value && y::type::value>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BOOL_HPP
