/*!
 * @file
 * Forward declares `boost::mpl11::Foldable`.
 */

#ifndef BOOST_MPL11_FWD_FOLDABLE_HPP
#define BOOST_MPL11_FWD_FOLDABLE_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/fwd/compose.hpp>
#include <boost/mpl11/fwd/not.hpp>
#include <boost/mpl11/fwd/quote.hpp>


namespace boost { namespace mpl11 {
    template <typename, typename, typename> struct lazy_foldr_impl;
    template <typename, typename, typename> struct foldr_impl;
    template <typename, typename, typename> struct foldl_impl;

    /*!
     * @ingroup typeclasses
     * @defgroup Foldable Foldable
     *
     * The `Foldable` typeclass is used for data structures that can
     * be folded.
     *
     *
     * ### Methods
     * `foldl`, `lazy_foldr` and `foldr`.
     *
     * ### Minimal complete definition
     * All the methods.
     *
     *
     * @note
     * `Foldable` is currently weak compared to its Haskell counterpart
     * because I have not found a suitable way to implement a Monoid yet.
     * Stay tuned.
     *
     *
     * @todo
     * Rewrite `all`, `any` and `none`'s unit test using a `Foldable`
     * instead of a `Sequence`.
     *
     * @{
     */
    template <typename Tag>
    struct Foldable;

    //! Right-associative fold of a structure using a binary operator.
    template <typename F, typename State, typename Structure>
    BOOST_MPL11_DOXYGEN_ALIAS(foldr, foldr_impl<F, State, Structure>);

    template <typename F, typename State, typename Structure>
    using foldr_t = typename foldr<F, State, Structure>::type;

    /*!
     * Lazy right-associative fold of a structure using a binary operator.
     *
     * In `lazy_foldr`, the state is passed to the binary operator as a
     * metafunction that should be evaluated to get the actual state.
     * This allows `lazy_foldr` to process infinite data structures,
     * to short-circuit and other useful tricks.
     */
    template <typename F, typename State, typename Structure>
    BOOST_MPL11_DOXYGEN_ALIAS(lazy_foldr, lazy_foldr_impl<F,State,Structure>);

    template <typename F, typename State, typename Structure>
    using lazy_foldr_t = typename lazy_foldr<F, State, Structure>::type;

    //! Left-associative fold of a structure using a binary operator.
    template <typename F, typename State, typename Structure>
    BOOST_MPL11_DOXYGEN_ALIAS(foldl, foldl_impl<F, State, Structure>);

    template <typename F, typename State, typename Structure>
    using foldl_t = typename foldl<F, State, Structure>::type;


    /*!
     * Boolean `StaticConstant` representing whether all the elements of
     * the structure satisfy the `Predicate`.
     */
    template <typename Predicate, typename Structure>
    struct all;

    template <typename Predicate, typename Structure>
    using all_t = typename all<Predicate, Structure>::type;

    /*!
     * Boolean `StaticConstant` representing whether none of the elements
     * of the structure satisfy the `Predicate`.
     */
    template <typename Predicate, typename Structure>
    using none = all<compose<quote<not_>, Predicate>, Structure>;

    template <typename Predicate, typename Structure>
    using none_t = typename none<Predicate, Structure>::type;

    /*!
     * Boolean `StaticConstant` representing whether any element of the
     * structure satisfies the `Predicate`.
     */
    template <typename Predicate, typename Structure>
    using any = not_<none<Predicate, Structure>>;

    template <typename Predicate, typename Structure>
    using any_t = typename any<Predicate, Structure>::type;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FOLDABLE_HPP
