/*!
 * @file
 * Forward declares `boost::mpl11::Bitwise`.
 */

#ifndef BOOST_MPL11_FWD_BITWISE_HPP
#define BOOST_MPL11_FWD_BITWISE_HPP

#include <boost/mpl11/detail/methods.hpp>
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
     * `bitand_`, `bitor_`, `bitxor`, `shift_left_c`, `shift_left`,
     * `shift_right_c` and `shift_right`.
     *
     * The `bitand_`, `bitor_` and `bitxor` methods can be invoked with more
     * than two arguments. In that case, the methods are left-associative like
     * their C++ equivalent. Specifically, `method<T1, ..., Tn>` is equivalent
     * to `method<method<T1, T2>::%type, ..., Tn>`, and `method<T1, T2>` uses
     * the usual tag dispatching technique.
     *
     * The `shift_right_c` and `shift_left_c` methods are dispatched in a
     * special way. The tag of their first operand is used both as `TagL`
     * and `TagR`.
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

#ifndef BOOST_MPL11_DOXYGEN_INVOKED
    namespace unchecked {
#endif

    //! Returns the bitwise `and` of the given objects (`T1 & T2 & ...Tn`).
    template <typename T1, typename T2>             struct bitand_;

    //! Returns the bitwise `or` of the given objects (`T1 | T2 | ...Tn`).
    template <typename T1, typename T2>             struct bitor_;

    //! Returns the bitwise `xor` of the given objects (`T1 ^ T2 ^ ...Tn`).
    template <typename T1, typename T2>             struct bitxor;

    //! Returns the result of bitwise right shift (`>>`) on the given object.
    template <typename T, detail::std_size_t Shift> struct shift_right_c;

    //! Equivalent to `shift_right_c<T, Shift::value>`;
    //! requires a non-negative `Shift`.
    template <typename T, typename Shift>           struct shift_right;

    //! Returns the result of bitwise left shift (`<<`) on the given object.
    template <typename T, detail::std_size_t Shift> struct shift_left_c;

    //! Equivalent to `shift_left_c<T, Shift::value>`;
    //! requires a non-negative `Shift`.
    template <typename T, typename Shift>           struct shift_left;

#ifndef BOOST_MPL11_DOXYGEN_INVOKED
    } // end namespace unchecked

    namespace checked {
        using unchecked::bitand_;
        using unchecked::bitor_;
        using unchecked::bitxor;
        using unchecked::shift_left_c;
        using unchecked::shift_right_c;

        template <typename T, typename Shift>
        struct shift_left;

        template <typename T, typename Shift>
        struct shift_right;
    }

    using methods::bitand_;
    using methods::bitor_;
    using methods::bitxor;
    using methods::shift_left_c;
    using methods::shift_left;
    using methods::shift_right_c;
    using methods::shift_right;
#endif // !BOOST_MPL11_DOXYGEN_INVOKED

    template <typename T1, typename T2>
    using bitand_t = typename bitand_<T1, T2>::type;

    template <typename T1, typename T2>
    using bitor_t = typename bitor_<T1, T2>::type;

    template <typename T1, typename T2>
    using bitxor_t = typename bitxor<T1, T2>::type;

    template <typename T, detail::std_size_t Shift>
    using shift_right_c_t = typename shift_right_c<T, Shift>::type;

    template <typename T, typename Shift>
    using shift_right_t = typename shift_right<T, Shift>::type;

    template <typename T, detail::std_size_t Shift>
    using shift_left_c_t = typename shift_left_c<T, Shift>::type;

    template <typename T, typename Shift>
    using shift_left_t = typename shift_left<T, Shift>::type;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BITWISE_HPP
