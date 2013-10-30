/*!
 * @file
 * Forward declares `boost::mpl11::ForwardSequence`.
 */

#ifndef BOOST_MPL11_FWD_FORWARD_SEQUENCE_HPP
#define BOOST_MPL11_FWD_FORWARD_SEQUENCE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * `Sequence` whose elements are arranged linearly.
     *
     *
     * ## Refinement of
     * `Sequence`, `Comparable`, `Orderable`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `Seq`      | A `ForwardSequence`
     *
     *
     * ## Valid expressions
     * | Expression         | Type
     * | ----------         | ----
     * | `front<Seq>::type` | Any type
     */
    struct ForwardSequence BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FORWARD_SEQUENCE_HPP
