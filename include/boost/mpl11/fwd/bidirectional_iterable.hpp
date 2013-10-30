/*!
 * @file
 * Forward declares `boost::mpl11::BidirectionalIterable`.
 */

#ifndef BOOST_MPL11_FWD_BIDIRECTIONAL_ITERABLE_HPP
#define BOOST_MPL11_FWD_BIDIRECTIONAL_ITERABLE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup mixins
     *
     * `ForwardIterable` whose iterators model the `BidirectionalIterator`
     * concept.
     *
     *
     * ## Refinement of
     * `ForwardIterable`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `I`        | A `BidirectionalIterable`
     *
     *
     * ## Valid expressions
     * | Expression       | Type
     * | ----------       | ----
     * | `begin<I>::type` | `BidirectionalIterator`
     * | `end<I>::type`   | `BidirectionalIterator`
     * | `back<I>::type`  | Any type
     */
    struct BidirectionalIterable BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BIDIRECTIONAL_ITERABLE_HPP
