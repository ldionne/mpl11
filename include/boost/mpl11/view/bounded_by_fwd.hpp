/*!
 * @file
 * Forward declares `boost::mpl11::view::bounded_by`.
 */

#ifndef BOOST_MPL11_VIEW_BOUNDED_BY_FWD_HPP
#define BOOST_MPL11_VIEW_BOUNDED_BY_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace view {
    /*!
     * @ingroup views
     * View onto the elements in the range delimited by [`First`, `Last`).
     *
     * `bounded_by` is either a @ref ForwardSequence, a
     * @ref BidirectionalSequence or a @ref RandomAccessSequence,
     * depending on the category of the underlying iterators.
     */
    template <typename First, typename Last>
    struct bounded_by BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::view

#endif // !BOOST_MPL11_VIEW_BOUNDED_BY_FWD_HPP
