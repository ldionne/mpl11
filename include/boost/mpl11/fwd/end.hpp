/*!
 * @file
 * Forward declares `boost::mpl11::end`.
 */

#ifndef BOOST_MPL11_FWD_BEGIN_HPP
#define BOOST_MPL11_FWD_BEGIN_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the past-the-end iterator of the sequence.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - If `Seq` is not a `Sequence`, `end<Seq>::type` is invalid instead
     *   of being the same as `mpl::void_`.
     */
    template <typename Seq>
    struct end;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BEGIN_HPP
