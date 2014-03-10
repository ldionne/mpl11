/*!
 * @file
 * Forward declares the @ref Ring typeclass.
 */

#ifndef BOOST_MPL11_FWD_RING_HPP
#define BOOST_MPL11_FWD_RING_HPP

#include <boost/mpl11/fwd/bool.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Ring Ring
     *
     * The `Ring` typeclass is used for `Group`s that also form a `Monoid`
     * under a second binary operation that distributes over the first.
     *
     * Instances of `Ring` must satisfy the following laws:
     *
        @code
            mult a (mult b c) == mult (mult a b) c

            mult one a == a
            mult a one == a

            mult a (plus b c) == plus (mult a b) (mult a c)
        @endcode
     *
     *
     * ### Refines
     * `Group`
     *
     * ### Methods
     * `mult` and `one`
     *
     * ### Minimal complete definition
     * All the methods.
     *
     * @{
     */
    template <typename Left, typename Right = Left, typename = true_>
    struct Ring;

    /*!
     * `Ring` operation.
     *
     * `mult` can be invoked with more than two arguments. Specifically,
     * `mult<x1, x2, xn...>` is equivalent to `mult<mult<x1, x2>, xn...>`.
     */
    template <typename x1, typename x2, typename ...xn>
    struct mult;

    //! Multiplicative identity for the given `Datatype`.
    template <typename Datatype>
    struct one;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_RING_HPP
