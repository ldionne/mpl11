/*!
 * @file
 * Forward declares `boost::mpl11::BidirectionalSequence`.
 */

#ifndef BOOST_MPL11_FWD_BIDIRECTIONAL_SEQUENCE_HPP
#define BOOST_MPL11_FWD_BIDIRECTIONAL_SEQUENCE_HPP

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
     * `last`, `init`
     *
     * ### Minimal complete definition
     * `last` and `init`.
     */
    template <typename Tag>
    struct BidirectionalSequence;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BIDIRECTIONAL_SEQUENCE_HPP
