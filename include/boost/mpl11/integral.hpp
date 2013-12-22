/*!
 * @file
 * Defines `boost::mpl11::Integral`.
 */

#ifndef BOOST_MPL11_INTEGRAL_HPP
#define BOOST_MPL11_INTEGRAL_HPP

#include <boost/mpl11/fwd/integral.hpp>

// Required by the forward declaration.
#include <boost/mpl11/arithmetic.hpp>
#include <boost/mpl11/bitwise.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/logical.hpp>
#include <boost/mpl11/orderable.hpp>

#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    // Logical
    template <typename N>
    struct Integral::not_impl
        : bool_<!static_cast<bool>(N::value)>
    { };

    // Comparable
    template <typename M, typename N>
    struct Integral::equal_impl
        : bool_<(M::value == N::value)>
    { };

    // Orderable
    template <typename M, typename N>
    struct Integral::less_impl
        : bool_<(M::value < N::value)>
    { };

#define BOOST_MPL11_INTEGRAL_BINOP(NAME, OPERATOR)                          \
    template <typename M, typename N>                                       \
    struct Integral::NAME ## _impl {                                        \
        using type = integral_c<                                            \
            decltype(M::value OPERATOR N::value),                           \
            (M::value OPERATOR N::value)                                    \
        >;                                                                  \
    };                                                                      \
/**/
    // Arithmetic
    BOOST_MPL11_INTEGRAL_BINOP(add, +)
    BOOST_MPL11_INTEGRAL_BINOP(subtract, -)
    BOOST_MPL11_INTEGRAL_BINOP(divide, /)
    BOOST_MPL11_INTEGRAL_BINOP(multiply, *)
    BOOST_MPL11_INTEGRAL_BINOP(modulo, %)

    // Bitwise
    BOOST_MPL11_INTEGRAL_BINOP(shift_left, <<)
    BOOST_MPL11_INTEGRAL_BINOP(shift_right, >>)
    BOOST_MPL11_INTEGRAL_BINOP(bitxor, ^)
    BOOST_MPL11_INTEGRAL_BINOP(bitor, |)
    BOOST_MPL11_INTEGRAL_BINOP(bitand, &)
#undef BOOST_MPL11_INTEGRAL_BINOP
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_HPP
