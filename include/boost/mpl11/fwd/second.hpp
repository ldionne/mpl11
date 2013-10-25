/*!
 * @file
 * Forward declares `boost::mpl11::second`.
 */

#ifndef BOOST_MPL11_FWD_SECOND_HPP
#define BOOST_MPL11_FWD_SECOND_HPP

namespace boost { namespace mpl11 {
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
    struct second;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_SECOND_HPP
