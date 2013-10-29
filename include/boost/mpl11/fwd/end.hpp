/*!
 * @file
 * Forward declares `boost::mpl11::end`.
 */

#ifndef BOOST_MPL11_FWD_BEGIN_HPP
#define BOOST_MPL11_FWD_BEGIN_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup iterable_intrinsics
     *
     * Returns the past-the-end iterator of the sequence.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - If `I` is not an `Iterable`, `end<I>::type` is invalid instead of
     *   being the same as `mpl::void_`.
     */
    template <typename I>
    struct end;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BEGIN_HPP
