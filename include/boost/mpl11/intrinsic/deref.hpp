/*!
 * @file
 * Defines `boost::mpl11::deref`.
 */

#ifndef BOOST_MPL11_INTRINSIC_DEREF_HPP
#define BOOST_MPL11_INTRINSIC_DEREF_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
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

#endif // !BOOST_MPL11_INTRINSIC_DEREF_HPP
