/*!
 * @file
 * Forward declares `boost::mpl11::BidirectionalSequence`.
 */

#ifndef BOOST_MPL11_FWD_BIDIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_FWD_BIDIRECTIONAL_SEQUENCE_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup BidirectionalSequence BidirectionalSequence
     *
     * Collection of types that can be traversed in both directions.
     *
     *
     * ### Refines
     * `ForwardSequence`
     *
     * ### Methods
     * `last` and `init`.
     *
     * ### Minimal complete definition
     * `last` and `init`.
     *
     *
     * @note
     * Instances of this typeclass can also instantiate `Comparable` and
     * `Orderable` for free by using `bidirectional_sequence_tag`.
     *
     * @{
     */
    template <typename Tag>
    struct BidirectionalSequence;

    /*!
     * Extract the elements before the last of a non-empty
     * `BidirectionalSequence`.
     *
     * Specifically, returns a concept-identical sequence containing all the
     * elements of the original sequence except the last one.
     */
    template <typename S>
    struct init;

    template <typename S>
    using init_t = typename init<S>::type;

    /*!
     * Returns the last element of a non-empty `BidirectionalSequence`.
     */
    template <typename S>
    struct last;

    template <typename S>
    using last_t = typename last<S>::type;

    //! @}

    /*!
     * @ingroup tags
     *
     * Tag representing the `BidirectionalSequence` typeclass.
     */
    struct bidirectional_sequence_tag BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BIDIRECTIONAL_SEQUENCE_HPP
