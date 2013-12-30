/*!
 * @file
 * Forward declares `boost::mpl11::Bitwise`.
 */

#ifndef BOOST_MPL11_FWD_BITWISE_HPP
#define BOOST_MPL11_FWD_BITWISE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Bitwise Bitwise
     *
     * The `Bitwise` typeclass is used for datatypes supporting the usual
     * bitwise operations.
     *
     *
     * ### Methods
     * `bitand_`, `bitor_`, `bitxor`, `shift_left` and `shift_right`.
     *
     * The `bitand_`, `bitor_` and `bitxor` methods can be invoked with more
     * than two arguments. In that case, the methods are left-associative like
     * their C++ equivalent. Specifically, `method<T1, ..., Tn>` is equivalent
     * to `method<method<T1, T2>::type, ..., Tn>`, and `method<T1, T2>` uses
     * the usual tag dispatching technique.
     *
     * The `shift_right` and `shift_left` methods are dispatched in a special
     * way. The tag of their first operand is used both as `TagL` and `TagR`.
     *
     * ### Minimal complete definition
     * All of the above methods.
     */
    template <typename TagL, typename TagR = TagL>
    struct Bitwise;

    /*!
     * @ingroup Bitwise
     * @ingroup methods
     * @{
     *
     * Returns the bitwise `and` of the given objects (`T1 & T2 & ...Tn`).
     */
    template <typename T1, typename T2, typename ...Tn>
    struct bitand_;

    template <typename T1, typename T2, typename ...Tn>
    using bitand_t = typename bitand_<T1, T2, Tn...>::type;

    /*!
     * Returns the bitwise `or` of the given objects (`T1 | T2 | ...Tn`).
     */
    template <typename T1, typename T2, typename ...Tn>
    struct bitor_;

    template <typename T1, typename T2, typename ...Tn>
    using bitor_t = typename bitor_<T1, T2, Tn...>::type;

    /*!
     * Returns the bitwise `xor` of the given objects (`T1 ^ T2 ^ ...Tn`).
     */
    template <typename T1, typename T2, typename ...Tn>
    struct bitxor_;

    template <typename T1, typename T2, typename ...Tn>
    using bitxor_t = typename bitxor_<T1, T2, Tn...>::type;

    /*!
     * Returns the result of bitwise right shift (`>>`) on the given object.
     */
    template <typename T, typename Shift>
    struct shift_right;

    template <typename T, typename Shift>
    using shift_right_t = typename shift_right<T, Shift>::type;

    /*!
     * Returns the result of bitwise left shift (`<<`) on the given object.
     */
    template <typename T, typename Shift>
    struct shift_left;

    template <typename T, typename Shift>
    using shift_left_t = typename shift_left<T, Shift>::type;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BITWISE_HPP
