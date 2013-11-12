/*!
 * @file
 * Forward declares `boost::mpl11::IntegralConstant`.
 */

#ifndef BOOST_MPL11_FWD_INTEGRAL_CONSTANT_HPP
#define BOOST_MPL11_FWD_INTEGRAL_CONSTANT_HPP

#include <boost/mpl11/fwd/arithmetic.hpp>
#include <boost/mpl11/fwd/bitwise.hpp>
#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/logical.hpp>
#include <boost/mpl11/fwd/orderable.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * Holder for a compile-time value of an integral type.
     *
     * Every `IntegralConstant` is also a nullary @ref Metafunction
     * returning itself. An integral constant object is implicitly
     * convertible to the corresponding runtime value of the wrapped
     * integral type.
     *
     *
     * ## Refinement of
     * `Arithmetic`, `Bitwise`, `Comparable`, `Logical`, `Orderable`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `N`        | An `IntegralConstant`
     *
     *
     * ## Valid expressions
     * | Expression                        | Type
     * | ----------                        | ----
     * | `N::value_type`                   | An integral type
     * | `N::value`                        | An integral constant expression
     * | `N::type`                         | `N`
     * | `constexpr N::value_type c = N{}` |
     */
    struct IntegralConstant
        : Arithmetic, Bitwise, Comparable, Logical, Orderable
    {
        // Logical
        template <typename N> struct not_impl;

#define BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(NAME) \
    template <typename M, typename N> struct NAME ## _impl;

        // Comparable
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(equal)

        // Orderable
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(less)

        // Arithmetic
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(add)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(substract)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(divide)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(multiply)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(modulo)

        // Bitwise
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(shift_left)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(shift_right)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(bitxor)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(bitor)
        BOOST_MPL11_INTEGRAL_CONSTANT_BINOP(bitand)

#undef BOOST_MPL11_INTEGRAL_CONSTANT_BINOP
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTEGRAL_CONSTANT_HPP
