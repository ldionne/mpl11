/*!
 * @file
 * Forward declares `boost::mpl11::iterator_range`.
 */

#ifndef BOOST_MPL11_FWD_ITERATOR_RANGE_HPP
#define BOOST_MPL11_FWD_ITERATOR_RANGE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequences
     *
     * `Sequence` containing the elements in the range delimited by
     * [`First`, `Last`).
     *
     * The actual concept modeled by `iterator_range` depends upon the
     * concept modeled by the underlying iterators. `iterator_range` can
     * model up to and including the `RandomAccessSequence` concept.
     */
    template <typename First, typename Last>
    struct iterator_range BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ITERATOR_RANGE_HPP
