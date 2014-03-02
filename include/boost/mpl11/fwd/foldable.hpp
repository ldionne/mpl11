/*!
 * @file
 * Forward declares the @ref Foldable typeclass.
 */

#ifndef BOOST_MPL11_FWD_FOLDABLE_HPP
#define BOOST_MPL11_FWD_FOLDABLE_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/fwd/bool.hpp>
#include <boost/mpl11/fwd/functional.hpp>
#include <boost/mpl11/fwd/logical.hpp>


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
     * `foldl` and `foldr`.
     *
     * ### Minimal complete definition
     * All the methods.
     *
     *
     * @todo
     * `Foldable` is currently weak compared to its Haskell counterpart
     * because I have not found a suitable way to implement a Monoid yet.
     *
     * @{
     */
    template <typename Datatype, typename = true_>
    struct Foldable;

    //! Right-associative fold of a structure using a binary operator.
    template <typename f, typename state, typename structure>
    struct foldr;


    //! Left-associative fold of a structure using a binary operator.
    template <typename f, typename state, typename structure>
    struct foldl;


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
