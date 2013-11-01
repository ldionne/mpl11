/*!
 * @file
 * Forward declares `boost::mpl11::DirectionalSequence`.
 */

#ifndef BOOST_MPL11_FWD_DIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_FWD_DIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup concepts
     *
     * `Sequence` whose elements are traversed in a definite order.
     *
     *
     * ## Refinement of
     * `Sequence`, `Comparable`, `Orderable`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `Seq`      | A `DirectionalSequence`
     *
     *
     * ## Valid expressions
     * | Expression         | Type
     * | ----------         | ----
     * | `front<Seq>::type` | Any type
     */
    struct DirectionalSequence BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_DIRECTIONAL_SEQUENCE_HPP
