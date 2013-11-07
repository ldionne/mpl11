/*!
 * @file
 * Forward declares `boost::mpl11::RandomAccessSequence`.
 */

#ifndef BOOST_MPL11_FWD_RANDOM_ACCESS_SEQUENCE_HPP
#define BOOST_MPL11_FWD_RANDOM_ACCESS_SEQUENCE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * `BidirectionalSequence` whose iterators model the
     * `RandomAccessIterator` concept.
     *
     *
     * ## Refinement of
     * `BidirectionalSequence`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `S`        | A `RandomAccessSequence`
     * | `N`        | An `IntegralConstant`
     *
     *
     * ## Valid expressions
     * | Expression              | Type
     * | ----------              | ----
     * | `mpl11::begin<S>::type` | `RandomAccessIterator`
     * | `mpl11::end<S>::type`   | `RandomAccessIterator`
     * | `mpl11::at<S, N>::type` | Any type
     */
    struct RandomAccessSequence BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_RANDOM_ACCESS_SEQUENCE_HPP
