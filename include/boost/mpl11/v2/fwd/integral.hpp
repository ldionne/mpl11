/*!
 * @file
 * Forward declares `boost::mpl11::Integral`.
 */

#ifndef BOOST_MPL11_FWD_INTEGRAL_HPP
#define BOOST_MPL11_FWD_INTEGRAL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Integral Integral
     *
     * Holder for a compile-time value of an integral type.
     *
     *
     * ### Refines
     * `Metafunction`
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
     * | `constexpr N::value_type c = N{}` |
     * | `constexpr N::value_type c = n()` |
     */
    template <typename Tag>
    struct Integral;

    /*!
     * @ingroup tags
     *
     * Tag representing the `Integral` typeclass.
     */
    struct integral_tag;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTEGRAL_HPP
