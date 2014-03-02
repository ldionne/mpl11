/*!
 * @file
 * Forward declares the @ref Bitwise typeclass.
 */

#ifndef BOOST_MPL11_FWD_BITWISE_HPP
#define BOOST_MPL11_FWD_BITWISE_HPP

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/integer.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Bitwise Bitwise
     *
     * Typeclass for datatypes supporting the usual bitwise operations.
     *
     *
     * ### Methods
     * `bitand_`, `bitor_`, `bitxor`, `compl_`,`shift_left` and `shift_right`.
     *
     * The `bitand_`, `bitor_` and `bitxor` methods can be invoked with more
     * than two arguments. In that case, the methods are left-associative like
     * their C++ equivalent. Specifically, `method<x1, ..., xn>` is equivalent
     * to `method<method<x1, x2>, ..., xn>`.
     *
     *
     * ### Minimal complete definition
     * All the methods.
     *
     * @{
     */
    template <typename Left, typename Right = Left>
    struct Bitwise;

    //! Bitwise `and` (`&&`).
    template <typename x1, typename x2, typename ...xn>
    struct bitand_;

    //! Bitwise `or` (`||`).
    template <typename x1, typename x2, typename ...xn>
    struct bitor_;

    //! Bitwise `xor` (`^`).
    template <typename x1, typename x2, typename ...xn>
    struct bitxor;

    /*!
     * Bitwise right shift (`>>`).
     *
     * `n` must be a non-negative @ref Integer representing the number of
     * positions to shift.
     */
    template <typename x, typename n>
    struct shift_right;

    //! Equivalent to `shift_right<x, size_t<n>>`.
    template <typename x, detail::std_size_t n>
    using shift_right_c = shift_right<x, size_t<n>>;

    /*!
     * Bitwise left shift (`<<`).
     *
     * `n` must be a non-negative @ref Integer representing the number of
     * positions to shift.
     */
    template <typename x, typename n>
    struct shift_left;

    //! Equivalent to `shift_left<x, size_t<n>>`.
    template <typename x, detail::std_size_t n>
    using shift_left_c = shift_left<x, size_t<n>>;

    //! Bitwise complement (`~`).
    template <typename x>
    struct compl_;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BITWISE_HPP
