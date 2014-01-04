/*!
 * @file
 * Forward declares `boost::mpl11::Integral`.
 */

#ifndef BOOST_MPL11_FWD_INTEGRAL_HPP
#define BOOST_MPL11_FWD_INTEGRAL_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/fwd/bitwise.hpp>
#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/orderable.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Integral Integral
     *
     * Holder for a compile-time value of an integral type.
     *
     *
     * ### Refines
     * `Comparable`, `Orderable` and `Bitwise`.
     *
     * ### Valid expressions
     * In the following table, `N` is an `Integral` datatype, and `n` is an
     * object of type `N`.
     *
     * | Expression                        | Type
     * | ----------                        | ----
     * | `N::value_type`                   | An integral type
     * | `N::value`                        | An integral constant expression
     * | `N::type`                         | `N`
     * | `constexpr N::value_type c = N{}` | n/a
     * | `constexpr N::value_type c = n()` | n/a
     */
    template <typename Tag>
    struct Integral;

    /*!
     * @ingroup tags
     *
     * Tag representing the `Integral` typeclass.
     */
    struct integral_tag BOOST_MPL11_IF_DOXYGEN({ });

    template <>
    struct Comparable<integral_tag, integral_tag>;

    template <>
    struct Orderable<integral_tag, integral_tag>;

    template <>
    struct Bitwise<integral_tag, integral_tag>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTEGRAL_HPP
