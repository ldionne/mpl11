/*!
 * @file
 * Forward declares `boost::mpl11::second`.
 */

#ifndef BOOST_MPL11_INTRINSIC_SECOND_FWD_HPP
#define BOOST_MPL11_INTRINSIC_SECOND_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct second; }

    /*!
     * @ingroup intrinsics
     *
     * Returns the second element of a pair.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - No default implementation is provided.
     * - The operation uses standard tag dispatching.
     */
    template <typename Pair>
    struct second
        : dispatch<tag::second, Pair>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_SECOND_FWD_HPP
