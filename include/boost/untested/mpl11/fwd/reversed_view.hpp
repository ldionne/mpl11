/*!
 * @file
 * Forward declares `boost::mpl11::reversed_view`.
 */

#ifndef BOOST_MPL11_FWD_REVERSED_VIEW_HPP
#define BOOST_MPL11_FWD_REVERSED_VIEW_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup views
     * View onto the elements of a sequence, in reverse order.
     *
     * `Sequence` is required to be a @ref BidirectionalSequence, but
     * the category of `reversed_view` depends upon the category of the
     * underlying `Sequence`.
     */
    template <typename Sequence>
    struct reversed_view BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_REVERSED_VIEW_HPP
