/*!
 * @file
 * Forward declares `boost::mpl11::ForwardSequence`.
 */

#ifndef BOOST_MPL11_FWD_FORWARD_SEQUENCE_HPP
#define BOOST_MPL11_FWD_FORWARD_SEQUENCE_HPP

#include <boost/mpl11/v2/fwd/comparable.hpp>
#include <boost/mpl11/v2/fwd/orderable.hpp>
#include <boost/mpl11/v2/fwd/tags.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup ForwardSequence ForwardSequence
     *
     * Collection of types that can be traversed in one direction.
     *
     *
     * ### Refines
     * - `Comparable` when the elements in the sequence are `Comparable`.
     * - `Orderable` when the elements in the sequence are `Orderable`.
     *
     * ### Methods
     * `head`, `tail`, `is_empty`
     *
     * ### Minimal complete definition
     * `head`, `tail` and `is_empty`.
     *
     *
     * @note
     * Instances of this typeclass can also instantiate `Comparable` and
     * `Orderable` for free by using `forward_sequence_tag`.
     */
    template <typename Tag>
    struct ForwardSequence;

    /*!
     * Default instantiation of the `Comparable` typeclass for
     * `ForwardSequence`s.
     *
     * Two `ForwardSequence`s are equal if their elements are equal when
     * compared side-by-side, and if both sequences run out of elements
     * at the same time, i.e. if they have the same length. The inequality
     * of two `ForwardSequence`s is defined in terms of their equality.
     */
    template <>
    struct Comparable<forward_sequence_tag, forward_sequence_tag>;

    /*!
     * Default instantiation of the `Orderable` typeclass for
     * `ForwardSequence`s.
     *
     * Less-than comparison for `ForwardSequence`s is defined as the
     * lexicographical comparison of their elements. Other comparison
     * operators are defined in terms of the less-than comparison.
     */
    template <>
    struct Orderable<forward_sequence_tag, forward_sequence_tag>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FORWARD_SEQUENCE_HPP
