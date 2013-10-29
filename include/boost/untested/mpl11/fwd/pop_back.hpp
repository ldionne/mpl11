/*!
 * @file
 * Forward declares `boost::mpl11::pop_back`.
 */

#ifndef BOOST_MPL11_FWD_POP_BACK_HPP
#define BOOST_MPL11_FWD_POP_BACK_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Returns a sequence with its last element removed.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `erase<Sequence, prior<end<Sequence>::type>::type>` if
     * `is_empty<Sequence>::type::value` is `false`, and a
     * compile-time assertion is triggered otherwise.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A compile-time assertion is triggered if the sequence is empty.
     */
    template <typename Sequence>
    struct pop_back;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_POP_BACK_HPP
