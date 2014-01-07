/*!
 * @file
 * Forward declares `boost::mpl11::Foldable`.
 */

#ifndef BOOST_MPL11_FWD_FOLDABLE_HPP
#define BOOST_MPL11_FWD_FOLDABLE_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
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
     * `foldl` and `foldr`.
     *
     * ### Minimal complete definition
     * All the methods.
     *
     *
     * @note
     * `Foldable` is currently weak compared to its Haskell counterpart
     * because I have not found a suitable way to implement a Monoid yet. Stay
     * tuned.
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

    //! Left-associative fold of a structure using a binary operator.
    template <typename F, typename State, typename Structure>
    BOOST_MPL11_DOXYGEN_ALIAS(foldl, foldl_impl<F, State, Structure>);

    template <typename F, typename State, typename Structure>
    using foldl_t = typename foldl<F, State, Structure>::type;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FOLDABLE_HPP
