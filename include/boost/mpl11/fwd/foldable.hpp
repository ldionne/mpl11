/*!
 * @file
 * Forward declares the @ref Foldable typeclass.
 */

#ifndef BOOST_MPL11_FWD_FOLDABLE_HPP
#define BOOST_MPL11_FWD_FOLDABLE_HPP

#include <boost/mpl11/detail/doxygen.hpp>
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
     * Provide a default implementation for `foldl1` and `foldr1`.
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
        compose<quote<and_>, predicate>,
        true_,
        structure
    >);

    //! Equivalent to `all<quote<id>, structure>`.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(all_of, all<quote<id>, structure>);

    /*!
     * Returns whether none of the elements of the structure satisfy the
     * `predicate`.
     */
    template <typename predicate, typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(none,
        all<compose<quote<not_>, predicate>, structure>);

    //! Equivalent to `none<quote<id>, structure>`.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(none_of, none<quote<id>, structure>);

    /*!
     * Returns whether any element of the structure satisfies the `predicate`.
     */
    template <typename predicate, typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(any, not_<none<predicate, structure>>);

    //! Equivalent to `any<quote<id>, structure>`.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(any_of, any<quote<id>, structure>);

    //! Compute the sum of the elements of a `structure`.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(sum,
        foldr<quote<plus>, zero<Integer>, structure>);

    //! Compute the product of the elements of a `structure`.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(product,
        foldr<quote<mult>, one<Integer>, structure>);

    /*!
     * The largest element of a non-empty structure with respect to
     * the given `predicate`.
     */
    template <typename predicate, typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(maximum_by,
        foldr1<bind<quote<if_>, predicate, arg<2>, arg<1>>, structure>);

    //! Returns the largest element of a non-empty structure.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(maximum, foldr1<quote<max>, structure>);

    /*!
     * The least element of a non-empty structure with respect to
     * the given `predicate`.
     */
    template <typename predicate, typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(minimum_by,
        foldr1<bind<quote<if_>, predicate, arg<1>, arg<2>>, structure>);

    //! Returns the least element of a non-empty structure.
    template <typename structure>
    BOOST_MPL11_DOXYGEN_ALIAS(minimum, foldr1<quote<min>, structure>);

    /*!
     * Invokes a metafunction class with the contents of a structure.
     *
     * Specifically, `unpack<structure, f>` is equivalent to
     * `apply<f, a0, ..., an>`, where `a0`, ...,`an` are the
     * elements in the structure.
     */
    template <typename structure, typename f>
    struct unpack;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FOLDABLE_HPP
