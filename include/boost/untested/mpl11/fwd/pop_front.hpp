/*!
 * @file
 * Forward declares `boost::mpl11::pop_front`.
 */

#ifndef BOOST_MPL11_FWD_POP_FRONT_HPP
#define BOOST_MPL11_FWD_POP_FRONT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Returns a sequence with its first element removed.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `erase<Sequence, begin<Sequence>::type>` if
     * `is_empty<Sequence>::type::value` is `false`, and a
     * compile-time assertion is triggered otherwise.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A compile-time assertion is triggered if the sequence is empty.
     */
    template <typename Sequence>
    struct pop_front;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_POP_FRONT_HPP
