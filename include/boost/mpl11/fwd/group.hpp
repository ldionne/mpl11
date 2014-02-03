/*!
 * @file
 * Forward declares the @ref Group typeclass.
 */

#ifndef BOOST_MPL11_FWD_GROUP_HPP
#define BOOST_MPL11_FWD_GROUP_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Group Group
     *
     * The `Group` typeclass is used for `Monoid`s where all objects have
     * an inverse w.r.t. the `Monoid` operation.
     *
     * Instances of `Group` must satisfy the following laws:
     *
        @code
            plus x (negate x) == zero
            plus (negate x) x == zero
        @endcode
     *
     * The method names refer to the group of numbers under addition.
     *
     *
     * ### Refines
     * `Monoid`
     *
     * ### Methods
     * `minus` and `negate`
     *
     * ### Minimal complete definition
     * All the methods.
     *
     *
     * @todo
     * Provide default implementations for `minus` and `negate`.
     *
     * @{
     */
    template <typename Left, typename Right = Left>
    struct Group;

    //! Equivalent to `plus<x, negate<y>>`.
    template <typename x, typename y>
    struct minus;

    //! Returns the inverse of `x`.
    template <typename x>
    struct negate;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_GROUP_HPP
