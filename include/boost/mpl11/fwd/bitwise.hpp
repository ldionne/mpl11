/*!
 * @file
 * Forward declares `boost::mpl11::Bitwise`.
 */

#ifndef BOOST_MPL11_FWD_BITWISE_HPP
#define BOOST_MPL11_FWD_BITWISE_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 {
    template <typename, typename>           struct bitand_impl;
    template <typename, typename>           struct bitor_impl;
    template <typename, typename>           struct bitxor_impl;
    template <typename, detail::std_size_t> struct shift_left_c_impl;
    template <typename, detail::std_size_t> struct shift_right_c_impl;
    template <typename>                     struct compl_impl;

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
     *
     * @todo
     * Implement multiple arguments as documented.
     *
     * @{
     */
    template <typename TagL, typename TagR = TagL>
    struct Bitwise;

    //! Returns the bitwise `and` of the given objects (`T1 & T2 & ...Tn`).
    template <typename T1, typename T2>
    BOOST_MPL11_DOXYGEN_ALIAS(bitand_, bitand_impl<T1, T2>);

    template <typename T1, typename T2>
    using bitand_t = typename bitand_<T1, T2>::type;


    //! Returns the bitwise `or` of the given objects (`T1 | T2 | ...Tn`).
    template <typename T1, typename T2>
    BOOST_MPL11_DOXYGEN_ALIAS(bitor_, bitor_impl<T1, T2>);

    template <typename T1, typename T2>
    using bitor_t = typename bitor_<T1, T2>::type;


    //! Returns the bitwise `xor` of the given objects (`T1 ^ T2 ^ ...Tn`).
    template <typename T1, typename T2>
    BOOST_MPL11_DOXYGEN_ALIAS(bitxor, bitxor_impl<T1, T2>);

    template <typename T1, typename T2>
    using bitxor_t = typename bitxor<T1, T2>::type;


    //! Returns the result of bitwise right shift (`>>`) on the given object.
    template <typename T, detail::std_size_t Shift>
    BOOST_MPL11_DOXYGEN_ALIAS(shift_right_c, shift_right_c_impl<T, Shift>);

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
    BOOST_MPL11_DOXYGEN_ALIAS(shift_left_c, shift_left_c_impl<T, Shift>);

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
    BOOST_MPL11_DOXYGEN_ALIAS(compl_, compl_impl<T>);

    template <typename T>
    using compl_t = typename compl_<T>::type;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BITWISE_HPP
