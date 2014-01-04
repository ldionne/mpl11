/*!
 * @file
 * Forward declares `boost::mpl11::StaticConstant`.
 */

#ifndef BOOST_MPL11_FWD_STATIC_CONSTANT_HPP
#define BOOST_MPL11_FWD_STATIC_CONSTANT_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/fwd/bitwise.hpp>
#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/orderable.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup StaticConstant StaticConstant
     *
     * Holder for a compile-time value of an integral type.
     *
     *
     * ### Refines
     * `Comparable`, `Orderable` and `Bitwise`.
     *
     * ### Valid expressions
     * In the following table, `N` is a `StaticConstant`, and `n` is an
     * object of type `N`.
     *
     * | Expression                        | Type
     * | ----------                        | ----
     * | `N::value_type`                   | An integral type
     * | `N::value`                        | An integral constant expression
     * | `N::type`                         | `N`
     * | `constexpr N::value_type c = N{}` | n/a
     * | `constexpr N::value_type c = n()` | n/a
     *
     *
     * @note
     * This typeclass is only provided for consistency with the rest
     * of the library, because it does not define any new methods.
     */
    struct StaticConstant;

    /*!
     * @ingroup tags
     *
     * Tag representing the `StaticConstant` typeclass.
     */
    struct static_constant_tag BOOST_MPL11_IF_DOXYGEN({ });

    template <>
    struct Comparable<static_constant_tag, static_constant_tag>;

    template <>
    struct Orderable<static_constant_tag, static_constant_tag>;

    template <>
    struct Bitwise<static_constant_tag, static_constant_tag>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_STATIC_CONSTANT_HPP
