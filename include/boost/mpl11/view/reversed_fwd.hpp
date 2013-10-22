/*!
 * @file
 * Forward declares `boost::mpl11::view::reversed`.
 */

#ifndef BOOST_MPL11_VIEW_REVERSED_FWD_HPP
#define BOOST_MPL11_VIEW_REVERSED_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     * View onto the elements of a sequence, in reverse order.
     *
     * `Sequence` is required to be a @ref BidirectionalSequence, but the
     * category of `reversed` depends upon the category of the underlying
     * `Sequence`.
     */
    template <typename Sequence>
    struct reversed BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view

#endif // !BOOST_MPL11_VIEW_REVERSED_FWD_HPP
