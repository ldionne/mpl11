/*!
 * @file
 * Forward declares `boost::mpl11::Couple`.
 */

#ifndef BOOST_MPL11_FWD_COUPLE_HPP
#define BOOST_MPL11_FWD_COUPLE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup mixins
     *
     * Mixin for holders of two arbitrary types.
     *
     * The first type can be retrieved using `mpl11::first`, and the second
     * using `mpl11::second`. `Couple`s are `Comparable` and `Orderable` if
     * both of their stored types are.
     */
    struct Couple BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_COUPLE_HPP
