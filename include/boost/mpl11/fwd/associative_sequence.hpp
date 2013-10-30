/*!
 * @file
 * Forward declares `boost::mpl11::AssociativeSequence`.
 */

#ifndef BOOST_MPL11_FWD_ASSOCIATIVE_SEQUENCE_HPP
#define BOOST_MPL11_FWD_ASSOCIATIVE_SEQUENCE_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup mixins
     *
     * `Sequence` allowing retrieval of elements based on keys.
     *
     *
     * ## Refinement of
     * `Sequence`, `Comparable`
     *
     *
     * ## Notation
     * | Expression | Description
     * | ---------- | -----------
     * | `Seq`      | An `AssociativeSequence`
     * | `Element`  | An element of `S`
     * | `Key`      | Any type
     * | `Default`  | Any type
     *
     *
     * ## Valid expressions
     * | Expression                     | Type
     * | ----------                     | ----
     * | `key_of<Seq, Element>::type`   | Any type
     * | `value_of<Seq, Element>::type` | Any type
     * | `at<Seq, Key>::type`           | Any type
     * | `at<Seq, Key, Default>::type`  | Any type
     * | `has_key<Seq, Key>`            | Boolean `IntegralConstant`
     */
    struct AssociativeSequence BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ASSOCIATIVE_SEQUENCE_HPP
