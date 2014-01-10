/*!
 * @file
 * Forward declares the @ref Bitwise typeclass.
 */

#ifndef BOOST_MPL11_FWD_BITWISE_HPP
#define BOOST_MPL11_FWD_BITWISE_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>


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
     * `bitand_`, `bitor_`, `bitxor`,`compl_`,  `shift_left_c`, `shift_left`,
     * `shift_right_c` and `shift_right`.
     *
     * The `bitand_`, `bitor_` and `bitxor` methods can be invoked with more
     * than two arguments. In that case, the methods are left-associative like
     * their C++ equivalent. Specifically, `method<T1, ..., Tn>` is equivalent
     * to `method<method<T1, T2>::%type, ..., Tn>`, and `method<T1, T2>` uses
     * the usual tag dispatching technique.
     *
     * The `compl_` and `shift_*` methods are dispatched in a special way.
     * The tag of their first operand is used both as `TagL` and `TagR`.
     *
     * The `shift_right` and `shift_left` methods are simple wrappers over
     * their `*_c` counterpart. They are provided for convenience but they
     * are not implemented inside the typeclass.
     *
     * ### Minimal complete definition
     * All of the above, except `shift_left` and `shift_right`.
     *
     * @{
     */
    template <typename TagL, typename TagR = TagL>
    struct Bitwise;

    //! Returns the bitwise `and` of the given objects (`T1 & T2 & ...Tn`).
    template <typename T1, typename T2, typename ...Tn>
    struct bitand_;

    template <typename T1, typename T2, typename ...Tn>
    using bitand_t = typename bitand_<T1, T2, Tn...>::type;


    //! Returns the bitwise `or` of the given objects (`T1 | T2 | ...Tn`).
    template <typename T1, typename T2, typename ...Tn>
    struct bitor_;

    template <typename T1, typename T2, typename ...Tn>
    using bitor_t = typename bitor_<T1, T2, Tn...>::type;


    //! Returns the bitwise `xor` of the given objects (`T1 ^ T2 ^ ...Tn`).
    template <typename T1, typename T2, typename ...Tn>
    struct bitxor;

    template <typename T1, typename T2, typename ...Tn>
    using bitxor_t = typename bitxor<T1, T2, Tn...>::type;


    //! Returns the result of bitwise right shift (`>>`) on the given object.
    template <typename T, detail::std_size_t Shift>
    struct shift_right_c;

    template <typename T, detail::std_size_t Shift>
    using shift_right_c_t = typename shift_right_c<T, Shift>::type;


    //! Equivalent to `shift_right_c<T, Shift::value>`;
    //! requires a non-negative `Shift`.
    template <typename T, typename Shift>
    struct shift_right;

    template <typename T, typename Shift>
    using shift_right_t = typename shift_right<T, Shift>::type;


    //! Returns the result of bitwise left shift (`<<`) on the given object.
    template <typename T, detail::std_size_t Shift>
    struct shift_left_c;

    template <typename T, detail::std_size_t Shift>
    using shift_left_c_t = typename shift_left_c<T, Shift>::type;


    //! Equivalent to `shift_left_c<T, Shift::value>`;
    //! requires a non-negative `Shift`.
    template <typename T, typename Shift>
    struct shift_left;

    template <typename T, typename Shift>
    using shift_left_t = typename shift_left<T, Shift>::type;


    //! Returns the bitwise complement of the given object (`~T`).
    template <typename T>
    struct compl_;

    template <typename T>
    using compl_t = typename compl_<T>::type;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BITWISE_HPP
