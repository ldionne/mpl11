/*!
 * @file
 * Forward declares `boost::mpl11::next`.
 */

#ifndef BOOST_MPL11_INTRINSIC_NEXT_FWD_HPP
#define BOOST_MPL11_INTRINSIC_NEXT_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct next; }

    /*!
     * @ingroup intrinsics
     *
     * Returns the next iterator in the sequence.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - No default implementation is provided.
     */
    template <typename Iterator>
    struct next
        : dispatch<tag::next, Iterator>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_NEXT_FWD_HPP
