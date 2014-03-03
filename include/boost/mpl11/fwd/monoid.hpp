/*!
 * @file
 * Forward declares the @ref Monoid typeclass.
 */

#ifndef BOOST_MPL11_FWD_MONOID_HPP
#define BOOST_MPL11_FWD_MONOID_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Monoid Monoid
     *
     * The `Monoid` typeclass is used for datatypes with an associative binary
     * operation that has an identity.
     *
     *
     * Instances of `Monoid` must satisfy the following laws:
     *
        @code
            plus zero x == x
            plus x zero == x
            plus x (plus y z) == plus (plus x y) z
        @endcode
     *
     * The method names refer to the monoid of numbers under addition, but
     * there are many other instances such as sequences under concatenation.
     * Some datatypes can be viewed as a monoid in more than one way, e.g.
     * both addition and multiplication on numbers.
     *
     *
     * ### Methods
     * `plus` and `zero`
     *
     * ### Minimal complete definition
     * All the methods.
     *
     * @{
     */
    template <typename Left, typename Right = Left>
    struct Monoid;

    /*!
     * Associative operation on a `Monoid`.
     *
     * `plus` can be invoked with more than two arguments. Specifically,
     * `plus<x1, x2, xn...>` is equivalent to `plus<plus<x1, x2>, xn...>`.
     */
    template <typename x1, typename x2, typename ...xn>
    struct plus;

    //! Additive identity for the given `Datatype`.
    template <typename Datatype>
    struct zero;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_MONOID_HPP
