/*!
 * @file
 * Defines the instances of `boost::mpl11::StaticConstant`.
 */

#ifndef BOOST_MPL11_STATIC_CONSTANT_HPP
#define BOOST_MPL11_STATIC_CONSTANT_HPP

#include <boost/mpl11/fwd/static_constant.hpp>

#include <boost/mpl11/bitwise.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/enumerable.hpp>
#include <boost/mpl11/integral.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/numeric.hpp>
#include <boost/mpl11/orderable.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct Comparable<static_constant_tag, static_constant_tag> {
        template <typename X, typename Y>
        using equal_impl = bool_<X::value == Y::value>;

        template <typename X, typename Y>
        using not_equal_impl = bool_<X::value != Y::value>;
    };

    template <>
    struct Orderable<static_constant_tag, static_constant_tag> {
        template <typename X, typename Y>
        using less_impl = bool_<(X::value < Y::value)>;

        template <typename X, typename Y>
        using less_equal_impl = bool_<(X::value <= Y::value)>;

        template <typename X, typename Y>
        using greater_impl = bool_<(X::value > Y::value)>;

        template <typename X, typename Y>
        using greater_equal_impl = bool_<(X::value >= Y::value)>;

        template <typename X, typename Y>
        using max_impl = typename detail::conditional<
            (X::value < Y::value), Y, X
        >::type;

        template <typename X, typename Y>
        using min_impl = typename detail::conditional<
            (X::value < Y::value), X, Y
        >::type;
    };

    template <>
    struct Enumerable<static_constant_tag> {
        template <typename X>
        using succ_impl = integral_c<decltype(X::value + 1), X::value + 1>;

        template <typename X>
        using pred_impl = integral_c<decltype(X::value - 1), X::value - 1>;
    };

    template <>
    struct Bitwise<static_constant_tag, static_constant_tag> {
        template <typename X, typename Y>
        using bitand_impl = integral_c<
            decltype(X::value & Y::value), X::value & Y::value
        >;

        template <typename X, typename Y>
        using bitor_impl = integral_c<
            decltype(X::value | Y::value), X::value | Y::value
        >;

        template <typename X, typename Y>
        using bitxor_impl = integral_c<
            decltype(X::value ^ Y::value), X::value ^ Y::value
        >;

        template <typename X, detail::std_size_t Shift>
        using shift_left_c_impl = integral_c<
            decltype(X::value << Shift), (X::value << Shift)
        >;

        template <typename X, detail::std_size_t Shift>
        using shift_right_c_impl = integral_c<
            decltype(X::value >> Shift), (X::value >> Shift)
        >;

        template <typename X>
        using compl_impl = integral_c<
            decltype(~X::value), ~X::value
        >;
    };

    template <>
    struct Numeric<static_constant_tag, static_constant_tag> {
        template <typename X, typename Y>
        using plus_impl = integral_c<
            decltype(X::value + Y::value), X::value + Y::value
        >;

        template <typename X, typename Y>
        using minus_impl = integral_c<
            decltype(X::value - Y::value), X::value - Y::value
        >;

        template <typename X, typename Y>
        using times_impl = integral_c<
            decltype(X::value * Y::value), X::value * Y::value
        >;

        template <typename X>
        using negate_impl = integral_c<decltype(-X::value), -X::value>;

        template <typename X>
        using abs_impl = integral_c<
            decltype(X::value < 0 ? -X::value : X::value),
            (X::value < 0 ? -X::value : X::value)
        >;

        template <typename X>
        using sign_impl = int_<
            (X::value < 0) ? -1 : (X::value > 0)
        >;
    };

    template <>
    struct Integral<static_constant_tag, static_constant_tag> {
        template <typename X, typename Y>
        using quot_impl = integral_c<
            decltype(X::value / Y::value), X::value / Y::value
        >;

        template <typename X, typename Y>
        using rem_impl = integral_c<
            decltype(X::value % Y::value), X::value % Y::value
        >;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_STATIC_CONSTANT_HPP
