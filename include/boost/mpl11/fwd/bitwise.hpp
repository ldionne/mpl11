/*!
 * @file
 * Forward declares `boost::mpl11::Bitwise`.
 */

#ifndef BOOST_MPL11_FWD_BITWISE_HPP
#define BOOST_MPL11_FWD_BITWISE_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


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
     * to `method<method<T1, T2>::%type, ..., Tn>`, and `method<T1, T2>` uses
     * the usual tag dispatching technique.
     *
     * The `shift_right` and `shift_left` methods are dispatched in a special
     * way. The tag of their first operand is used both as `TagL` and `TagR`.
     *
     * ### Minimal complete definition
     * All of the above methods.
     *
     *
     * @todo
     * Implement multiple arguments as documented.
     *
     * @{
     */
    template <typename TagL, typename TagR = TagL>
    struct Bitwise;

    /*!
     * Returns the bitwise `and` of the given objects (`T1 & T2 & ...Tn`).
     */
    template <typename T1, typename T2>
    struct bitand_;

    template <typename T1, typename T2>
    using bitand_t = typename bitand_<T1, T2>::type;

    /*!
     * Returns the bitwise `or` of the given objects (`T1 | T2 | ...Tn`).
     */
    template <typename T1, typename T2>
    struct bitor_;

    template <typename T1, typename T2>
    using bitor_t = typename bitor_<T1, T2>::type;

    /*!
     * Returns the bitwise `xor` of the given objects (`T1 ^ T2 ^ ...Tn`).
     */
    template <typename T1, typename T2>
    struct bitxor;

    template <typename T1, typename T2>
    using bitxor_t = typename bitxor<T1, T2>::type;

    /*!
     * Returns the result of bitwise right shift (`>>`) on the given object.
     */
    template <typename T, typename Shift>
    struct shift_right;

    template <typename T, typename Shift>
    using shift_right_t = typename shift_right<T, Shift>::type;

    /*!
     * Alias to `shift_right<T, size_t<Shift>>`; provided for convenience.
     */
    template <typename T, detail::std_size_t Shift>
    BOOST_MPL11_DOXYGEN_ALIAS(shift_right_c, shift_right<T, size_t<Shift>>);

    template <typename T, detail::std_size_t Shift>
    using shift_right_c_t = typename shift_right<T, size_t<Shift>>::type;

    /*!
     * Returns the result of bitwise left shift (`<<`) on the given object.
     */
    template <typename T, typename Shift>
    struct shift_left;

    template <typename T, typename Shift>
    using shift_left_t = typename shift_left<T, Shift>::type;

    /*!
     * Alias to `shift_left<T, size_t<Shift>>`; provided for convenience.
     */
    template <typename T, detail::std_size_t Shift>
    BOOST_MPL11_DOXYGEN_ALIAS(shift_left_c, shift_left<T, size_t<Shift>>);

    template <typename T, detail::std_size_t Shift>
    using shift_left_c_t = typename shift_left<T, size_t<Shift>>::type;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BITWISE_HPP
