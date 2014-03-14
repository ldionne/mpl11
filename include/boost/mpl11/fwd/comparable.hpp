/*!
 * @file
 * Forward declares the @ref Comparable typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FWD_COMPARABLE_HPP
#define BOOST_MPL11_FWD_COMPARABLE_HPP

#include <boost/mpl11/fwd/bool.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Comparable Comparable
     *
     * The `Comparable` typeclass defines equality and inequality.
     *
     *
     * ### Methods
     * `equal` and `not_equal`.
     *
     *
     * ### Minimal complete definition
     * Either `equal` or `not_equal`.
     *
     * @{
     */
    template <typename Left, typename Right = Left, typename = true_>
    struct Comparable;

    /*!
     * Returns whether the given objects are equal.
     *
     * This method can be invoked with more than two arguments. Specifically,
     * `equal<x1, x2, xs...>` is equivalent to
     * `and_<equal<x1, x2>, equal<x2, xs...>>`, and `equal<x1, x2>`
     * uses the usual dispatching technique.
     */
    template <typename x1, typename x2, typename ...xs>
    struct equal;

    /*!
     * Returns whether the given objects are unequal.
     *
     * Unlike `equal`, this method can't be invoked with more than two
     * arguments. The reason is that `not_equal` is not transitive and
     * its behavior with more than two arguments is not equivalent to
     * `not_<equal<...>>`, which is confusing.
     */
    template <typename x, typename y>
    struct not_equal;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_COMPARABLE_HPP
