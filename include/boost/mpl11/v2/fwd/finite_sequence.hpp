/*!
 * @file
 * Forward declares `boost::mpl11::FiniteSequence`.
 */

#ifndef BOOST_MPL11_FWD_FINITE_SEQUENCE_HPP
#define BOOST_MPL11_FWD_FINITE_SEQUENCE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup typeclasses
     * @defgroup FiniteSequence FiniteSequence
     *
     * Sequence containing a finite number of elements.
     *
     *
     * ### Refines
     * `ForwardSequence`
     *
     * ### Methods
     * `unpack`, `length`
     *
     * ### Minimal complete definition
     * Nothing; everything is provided using the methods of `ForwardSequence`.
     */
    template <typename Tag>
    struct FiniteSequence;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FINITE_SEQUENCE_HPP
