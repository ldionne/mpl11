/*!
 * @file
 * Forward declares `boost::mpl11::is_empty`.
 */

#ifndef BOOST_MPL11_FWD_IS_EMPTY_HPP
#define BOOST_MPL11_FWD_IS_EMPTY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns whether a `Sequence` is empty.
     *
     *
     * @warning
     * This intrinsic replaces the `mpl::empty` intrinsic from the
     * original MPL.
     */
    template <typename Sequence>
    struct is_empty;

    template <typename Sequence>
    using is_empty_t = typename is_empty<Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IS_EMPTY_HPP
