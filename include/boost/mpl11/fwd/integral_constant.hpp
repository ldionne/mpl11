/*!
 * @file
 * Forward declares `boost::mpl11::IntegralConstant`.
 */

#ifndef BOOST_MPL11_FWD_INTEGRAL_CONSTANT_HPP
#define BOOST_MPL11_FWD_INTEGRAL_CONSTANT_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


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
    struct IntegralConstant BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTEGRAL_CONSTANT_HPP
