/*!
 * @file
 * Forward declares `boost::mpl11::Couple`.
 */

#ifndef BOOST_MPL11_FWD_COUPLE_HPP
#define BOOST_MPL11_FWD_COUPLE_HPP

#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/orderable.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * %Type holding two arbitrary types.
     *
     * The first type can be retrieved using `mpl11::first`, and the second
     * using `mpl11::second`. `Couple`s are `Comparable` and `Orderable` if
     * both of their stored types are.
     */
    struct Couple : Comparable, Orderable {

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
        //! This operation must be provided by the user.
        template <typename Couple>
        struct first_impl;

        //! This operation must be provided by the user.
        template <typename Couple>
        struct second_impl;
#endif

        //! Performs a lexicographical comparison of the two couples.
        template <typename Couple1, typename Couple2>
        struct less_impl;

        //! Performs a memberwise comparison of the two couples.
        template <typename Couple1, typename Couple2>
        struct equal_impl;
    };

    /*!
     * @ingroup intrinsics
     *
     * Returns the second element of a pair.
     *
     *
     * @warning
     * In the original MPL, `mpl11::second` was a trivial metafunction
     * fetching `Pair::second`. `mpl11::second` is now an intrinsic.
     */
    template <typename Pair>
    struct second;

    template <typename Pair>
    using second_t = typename second<Pair>::type;

    /*!
     * @ingroup intrinsics
     *
     * Returns the first element of a pair.
     *
     *
     * @warning
     * In the original MPL, `mpl11::first` was a trivial metafunction
     * fetching `Pair::first`. `mpl11::first` is now an intrinsic.
     */
    template <typename Pair>
    struct first;

    template <typename Pair>
    using first_t = typename first<Pair>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_COUPLE_HPP
