/*!
 * @file
 * Forward declares `boost::mpl11::back`.
 */

#ifndef BOOST_MPL11_FWD_BACK_HPP
#define BOOST_MPL11_FWD_BACK_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Returns the last element of a @ref BidirectionalSequence if there is
     * such an element, and triggers a compile-time assertion otherwise.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `deref<prior<end<Sequence>::type>::type>` if
     * `is_empty<Sequence>::type::value` is `false`, and a
     * compile-time assertion is triggered otherwise.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A compile-time assertion is triggered if the sequence is empty.
     */
    template <typename Sequence>
    struct back;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BACK_HPP
