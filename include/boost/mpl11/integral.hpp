/*!
 * @file
 * Defines `boost::mpl11::Integral`.
 */

#ifndef BOOST_MPL11_INTEGRAL_HPP
#define BOOST_MPL11_INTEGRAL_HPP

#include <boost/mpl11/fwd/integral.hpp>

#include <boost/mpl11/bitwise.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/orderable.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct Comparable<integral_tag, integral_tag> {
        template <typename X, typename Y>
        using equal_impl = bool_<X::value == Y::value>;

        template <typename X, typename Y>
        using not_equal_impl = bool_<X::value != Y::value>;
    };

    template <>
    struct Orderable<integral_tag, integral_tag> {
        template <typename X, typename Y>
        using less_impl = bool_<(X::value < Y::value)>;

        template <typename X, typename Y>
        using less_equal_impl = bool_<(X::value <= Y::value)>;

        template <typename X, typename Y>
        using greater_impl = bool_<(X::value > Y::value)>;

        template <typename X, typename Y>
        using greater_equal_impl = bool_<(X::value >= Y::value)>;
    };

    template <>
    struct Bitwise<integral_tag, integral_tag> {
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_HPP
