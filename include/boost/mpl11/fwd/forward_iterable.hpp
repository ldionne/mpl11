/*!
 * @file
 * Forward declares `boost::mpl11::ForwardIterable`.
 */

#ifndef BOOST_MPL11_FWD_FORWARD_ITERABLE_HPP
#define BOOST_MPL11_FWD_FORWARD_ITERABLE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup mixins
     *
     * `Iterable` whose elements are arranged in a sequential order.
     *
     *
     * ## Refinement of
     * `Iterable`, `Comparable`, `Orderable`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `I`        | A `ForwardIterable`
     *
     *
     * ## Valid expressions
     * | Expression       | Type
     * | ----------       | ----
     * | `front<I>::type` | Any type
     */
    struct ForwardIterable BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FORWARD_ITERABLE_HPP
