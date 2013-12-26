/*!
 * @file
 * Forward declares `boost::mpl11::Arithmetic`.
 */

#ifndef BOOST_MPL11_FWD_ARITHMETIC_HPP
#define BOOST_MPL11_FWD_ARITHMETIC_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Arithmetic Arithmetic
     *
     * The `Arithmetic` typeclass is used for datatypes supporting the usual
     * arithmetic operations.
     *
     *
     * ### Methods
     * `add`, `subtract`, `modulo`, `divide` and `multiply`.
     *
     * All of these methods except `modulo` can be invoked with more than two
     * arguments. In that case, the methods are left-associative like their
     * C++ equivalent. Specifically, `method<T1, ..., Tn>` is equivalent to
     * `method<method<T1, T2>::type, ..., Tn>`, and `method<T1, T2>` uses the
     * usual tag dispatching technique.
     *
     * ### Minimal complete definition
     * All of the above methods.
     */
    template <typename TagL, typename TagR>
    struct Arithmetic;

    /*!
     * @ingroup Arithmetic
     * @ingroup methods
     * @{
     *
     * Returns the sum of the given objects (`T1 + T2 + ...Tn`).
     */
    template <typename T1, typename T2, typename ...Tn>
    struct add;

    template <typename T1, typename T2, typename ...Tn>
    using add_t = typename add<T1, T2, Tn...>::type;

    /*!
     * Returns the subtraction of the given objects (`T1 - T2 - ...Tn`).
     */
    template <typename T1, typename T2, typename ...Tn>
    struct subtract;

    template <typename T1, typename T2, typename ...Tn>
    using subtract_t = typename subtract<T1, T2, Tn...>::type;

    /*!
     * Returns the product of the given objects (`T1 * T2 * ...Tn`).
     */
    template <typename T1, typename T2, typename ...Tn>
    struct multiply;

    template <typename T1, typename T2, typename ...Tn>
    using multiply_t = typename multiply<T1, T2, Tn...>::type;

    /*!
     * Returns the division of the given objects (`T1 / T2 / ...Tn`).
     */
    template <typename T1, typename T2, typename ...Tn>
    struct divide;

    template <typename T1, typename T2, typename ...Tn>
    using divide_t = typename divide<T1, T2, Tn...>::type;

    /*!
     * Returns the modulo of the given objects (`T1 % T2`).
     */
    template <typename T1, typename T2>
    struct modulo;

    template <typename T1, typename T2>
    using modulo_t = typename modulo<T1, T2>::type;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ARITHMETIC_HPP
