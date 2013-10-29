/*!
 * @file
 * Forward declares `boost::mpl11::is_empty`.
 */

#ifndef BOOST_MPL11_FWD_IS_EMPTY_HPP
#define BOOST_MPL11_FWD_IS_EMPTY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup iterable_intrinsics
     *
     * Returns whether an `Iterable` is empty.
     *
     *
     * @warning
     * This intrinsic replaces the `mpl::empty` intrinsic from the
     * original MPL.
     */
    template <typename I>
    struct is_empty;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IS_EMPTY_HPP
