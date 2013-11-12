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
     * Type holding two arbitrary types.
     *
     * The first type can be retrieved using `mpl11::first`, and the second
     * using `mpl11::second`. `Couple`s are `Comparable` and `Orderable` if
     * both of their stored types are.
     */
    struct Couple : Comparable, Orderable {
        //! This operation must be provided by the user.
        template <typename Couple>
        struct first_impl;

        //! This operation must be provided by the user.
        template <typename Couple>
        struct second_impl;

        //! Performs a lexicographical comparison of the two couples.
        template <typename Couple1, typename Couple2>
        struct less_impl;

        //! Performs a memberwise comparison of the two couples.
        template <typename Couple1, typename Couple2>
        struct equal_impl;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_COUPLE_HPP
