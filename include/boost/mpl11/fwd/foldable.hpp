/*!
 * @file
 * Forward declares the @ref Foldable typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FWD_FOLDABLE_HPP
#define BOOST_MPL11_FWD_FOLDABLE_HPP

#include <boost/mpl11/detail/config.hpp>
#include <boost/mpl11/fwd/bool.hpp>
#include <boost/mpl11/fwd/functional.hpp>
#include <boost/mpl11/fwd/integer.hpp>
#include <boost/mpl11/fwd/logical.hpp>
#include <boost/mpl11/fwd/monoid.hpp>
#include <boost/mpl11/fwd/orderable.hpp>
#include <boost/mpl11/fwd/ring.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup Foldable Foldable
     *
     * The `Foldable` typeclass is used for data structures that can
     * be folded.
     *
     *
     * ### Methods
     * `foldl`, `foldl1`, `foldr` and `foldr1`.
     *
     * ### Minimal complete definition
     * All the methods.
     *
     * @todo
     * - Provide a default implementation for `foldl1` and `foldr1`.
     * - Consider removing `unpack` or moving it elsewhere, maybe
     *   @ref Functional.
     *
     * @{
     */
    template <typename Datatype, typename = true_>
    struct Foldable;

    //! Right-associative fold of a structure using a binary operator.
    template <typename f, typename state, typename structure>
    struct foldr;

    /*!
     * Variant of `foldr` that has no base case, and thus may only be
     * applied to non-empty structures.
     */
    template <typename f, typename structure>
    struct foldr1;


    //! Left-associative fold of a structure using a binary operator.
    template <typename f, typename state, typename structure>
    struct foldl;

    /*!
     * Variant of `foldl` that has no base case, and thus may only be
     * applied to non-empty structures.
     */
    template <typename f, typename structure>
    struct foldl1;


    /*!
     * Returns whether all the elements of the structure satisfy the
     * `predicate`.
     */
    template <typename predicate, typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(all, foldr<
        compose<lift<and_>, predicate>,
        true_,
        structure
    >);

    //! Equivalent to `all<lift<id>, structure>`.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(all_of, all<lift<id>, structure>);

    /*!
     * Returns whether none of the elements of the structure satisfy the
     * `predicate`.
     */
    template <typename predicate, typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(none,
        all<compose<lift<not_>, predicate>, structure>);

    //! Equivalent to `none<lift<id>, structure>`.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(none_of, none<lift<id>, structure>);

    /*!
     * Returns whether any element of the structure satisfies the `predicate`.
     */
    template <typename predicate, typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(any, not_<none<predicate, structure>>);

    //! Equivalent to `any<lift<id>, structure>`.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(any_of, any<lift<id>, structure>);

    //! Compute the sum of the elements of a `structure`.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(sum,
        foldr<lift<plus>, zero<Integer>, structure>);

    //! Compute the product of the elements of a `structure`.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(product,
        foldr<lift<mult>, one<Integer>, structure>);

    /*!
     * The largest element of a non-empty structure with respect to
     * the given `predicate`.
     */
    template <typename predicate, typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(maximum_by,
        foldr1<bind<lift<if_>, predicate, arg<2>, arg<1>>, structure>);

    //! Returns the largest element of a non-empty structure.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(maximum, foldr1<lift<max>, structure>);

    /*!
     * The least element of a non-empty structure with respect to
     * the given `predicate`.
     */
    template <typename predicate, typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(minimum_by,
        foldr1<bind<lift<if_>, predicate, arg<1>, arg<2>>, structure>);

    //! Returns the least element of a non-empty structure.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(minimum, foldr1<lift<min>, structure>);

    /*!
     * Invokes a metafunction class with the contents of a structure.
     *
     * Specifically, `unpack<f, structure>` is equivalent to
     * `apply<f, a0, ..., an>`, where `a0`, ...,`an` are the
     * elements in the structure.
     */
    template <typename f, typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(unpack,
        apply<foldl<lift<partial>, f, structure>>);
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FOLDABLE_HPP
