/*!
 * @file
 * Forward declares `boost::mpl11::Integral`.
 */

#ifndef BOOST_MPL11_FWD_INTEGRAL_HPP
#define BOOST_MPL11_FWD_INTEGRAL_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Integral Integral
     *
     * Holder for a compile-time value of an integral type.
     *
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTEGRAL_HPP
