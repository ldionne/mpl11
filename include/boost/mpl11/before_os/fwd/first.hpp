/*!
 * @file
 * Forward declares `boost::mpl11::first`.
 */

#ifndef BOOST_MPL11_FWD_FIRST_HPP
#define BOOST_MPL11_FWD_FIRST_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct first; }

    /*!
     * @ingroup intrinsics
     *
     * Returns the first element of a pair.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - No default implementation is provided.
     * - The intrinsic uses standard tag dispatching.
     */
    template <typename Pair>
    struct first
        : dispatch<tag::first, Pair>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FIRST_HPP
