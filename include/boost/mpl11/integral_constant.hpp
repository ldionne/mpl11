/*!
 * @file
 * Defines `boost::mpl11::IntegralConstant`.
 */

#ifndef BOOST_MPL11_INTEGRAL_CONSTANT_HPP
#define BOOST_MPL11_INTEGRAL_CONSTANT_HPP

#include <boost/mpl11/fwd/integral_constant.hpp>

#include <boost/mpl11/arithmetic.hpp>
#include <boost/mpl11/bitwise.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/boolean.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/value.hpp>


namespace boost { namespace mpl11 {
    template <template <typename T, T v> class integral_constant>
    struct IntegralConstant
        : Arithmetic, Bitwise, Boolean, Comparable, Orderable, Value
    {
        // Boolean
        template <typename N>
        struct not_impl {
            using type = bool_<!static_cast<bool>(N::value)>;
        };

        // Comparable
        template <typename M, typename N>
        struct equal_impl {
            using type = bool_<M::value == N::value>;
        };

        // Orderable
        template <typename M, typename N>
        struct less_impl {
            using type = bool_<M::value < N::value>;
        };

#define BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(NAME, OPERATOR)                 \
        template <typename M, typename N>                                   \
        struct NAME ## _impl {                                              \
            using type = integral_constant<                                 \
                decltype(M::value OPERATOR N::value),                       \
                (M::value OPERATOR N::value)                                \
            >;                                                              \
        };                                                                  \
/**/
        // Arithmetic
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(add, +)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(substract, -)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(divide, /)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(multiply, *)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(modulo, %)

        // Bitwise
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(shift_left, <<)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(shift_right, >>)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(bitxor, ^)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(bitor, |)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(bitand, &)
#undef BOOST_MPL11_INTEGRAL_CONSTANT_BINOP
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_CONSTANT_HPP
