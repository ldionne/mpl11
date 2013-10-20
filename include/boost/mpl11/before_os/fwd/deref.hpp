/*!
 * @file
 * Forward declares `boost::mpl11::deref`.
 */

#ifndef BOOST_MPL11_FWD_DEREF_HPP
#define BOOST_MPL11_FWD_DEREF_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct deref; }

    /*!
     * @ingroup intrinsics
     *
     * Dereferences an iterator.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - No default implementation is provided.
     */
    template <typename Iterator>
    struct deref
        : dispatch<tag::deref, Iterator>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_DEREF_HPP
