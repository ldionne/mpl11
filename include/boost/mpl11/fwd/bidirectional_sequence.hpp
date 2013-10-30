/*!
 * @file
 * Forward declares `boost::mpl11::BidirectionalSequence`.
 */

#ifndef BOOST_MPL11_FWD_BIDIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_FWD_BIDIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup mixins
     *
     * `ForwardSequence` whose iterators model the `BidirectionalIterator`
     * concept.
     *
     *
     * ## Refinement of
     * `ForwardSequence`
     *
     *
     * ## Notation
     * | Expression   | Description
     * | ----------   | -----------
     * | `Seq`        | A `BidirectionalSequence`
     *
     *
     * ## Valid expressions
     * | Expression         | Type
     * | ----------         | ----
     * | `begin<Seq>::type` | `BidirectionalIterator`
     * | `end<Seq>::type`   | `BidirectionalIterator`
     * | `back<Seq>::type`  | Any type
     */
    struct BidirectionalSequence BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BIDIRECTIONAL_SEQUENCE_HPP
