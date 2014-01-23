/*!
 * @file
 * Forward declares `boost::mpl11::StaticConstant`.
 */

#ifndef BOOST_MPL11_FWD_STATIC_CONSTANT_HPP
#define BOOST_MPL11_FWD_STATIC_CONSTANT_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/fwd/bitwise.hpp>
#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/enumerable.hpp>
#include <boost/mpl11/fwd/integral.hpp>
#include <boost/mpl11/fwd/numeric.hpp>
#include <boost/mpl11/fwd/orderable.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup StaticConstant StaticConstant
     *
     * Holder for a compile-time value of an integral type.
     *
     *
     * ### Provides
     * `Comparable`, `Orderable`, `Enumerable`, `Bitwise`, `Numeric` and
     * `Integral`.
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
     * @{
     */
    struct StaticConstant;

    /*!
     * Tag representing the `StaticConstant` typeclass.
     *
     * @ingroup tags
     */
    struct static_constant_tag BOOST_MPL11_IF_DOXYGEN({ });

    //! Default instantiation of `Enumerable` for `StaticConstant`s.
    template <>
    struct Enumerable<static_constant_tag>;

    //! Default instantiation of `Comparable` for `StaticConstant`s.
    template <>
    struct Comparable<static_constant_tag, static_constant_tag>
    BOOST_MPL11_IF_DOXYGEN({ });

    //! Default instantiation of `Orderable` for `StaticConstant`s.
    template <>
    struct Orderable<static_constant_tag, static_constant_tag>
    BOOST_MPL11_IF_DOXYGEN({ });

    //! Default instantiation of `Bitwise` for `StaticConstant`s.
    template <>
    struct Bitwise<static_constant_tag, static_constant_tag>
    BOOST_MPL11_IF_DOXYGEN({ });

    //! Default instantiation of `Numeric` for `StaticConstant`s.
    template <>
    struct Numeric<static_constant_tag, static_constant_tag>
    BOOST_MPL11_IF_DOXYGEN({ });

    //! Default instantiation of `Integral` for `StaticConstant`s.
    template <>
    struct Integral<static_constant_tag, static_constant_tag>
    BOOST_MPL11_IF_DOXYGEN({ });
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_STATIC_CONSTANT_HPP
