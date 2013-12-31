/*!
 * @file
 * Forward declares `boost::mpl11::end`.
 */

#ifndef BOOST_MPL11_FWD_END_HPP
#define BOOST_MPL11_FWD_END_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the past-the-end iterator of a `Sequence`.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - If `%Sequence` is not a `Sequence`, `end<%Sequence>::type` is
     *   invalid instead of being the same as `mpl::void_`.
     */
    template <typename Sequence>
    struct end;

    template <typename Sequence>
    using end_t = typename end<Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_END_HPP
