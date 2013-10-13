/*!
 * @file
 * Forward declares `boost::mpl11::iterator_range`.
 */

#ifndef BOOST_MPL11_FWD_ITERATOR_RANGE_HPP
#define BOOST_MPL11_FWD_ITERATOR_RANGE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup views
     * View onto the elements in the range delimited by [`First`, `Last`).
     *
     * `iterator_range` is either a @ref ForwardSequence, a
     * @ref BidirectionalSequence or a @ref RandomAccessSequence,
     * depending on the category of the underlying iterators.
     */
    template <typename First, typename Last>
    struct iterator_range BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ITERATOR_RANGE_HPP
