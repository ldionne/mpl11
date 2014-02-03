/*!
 * @file
 * Forward declares the @ref Field typeclass.
 */

#ifndef BOOST_MPL11_FWD_FIELD_HPP
#define BOOST_MPL11_FWD_FIELD_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Field Field
     *
     * The `Field` typeclass is used for `Ring`s whose non-zero elements form
     * a `Group` under multiplication.
     *
     *
     * ### Refines
     * `Ring`
     *
     * ### Methods
     * `recip` and `div`
     *
     * ### Minimal complete definition
     * All the methods.
     *
     *
     * @todo
     * Provide default implementations for `recip` and `div`.
     *
     * @{
     */
    template <typename Left, typename Right = Left>
    struct Field;

    //! Equivalent to `mult<x, recip<y>>`.
    template <typename x, typename y>
    struct div;

    //! Multiplicative inverse of `x`.
    template <typename x>
    struct recip;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FIELD_HPP
