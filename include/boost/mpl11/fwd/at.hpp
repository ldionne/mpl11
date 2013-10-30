/*!
 * @file
 * Forward declares `boost::mpl11::at` and defines `boost::mpl::at_c`.
 */

#ifndef BOOST_MPL11_FWD_AT_HPP
#define BOOST_MPL11_FWD_AT_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup sequence_intrinsics
     *
     * Returns the `N`th element of a sequence if `N` is in the bounds of the
     * sequence, and triggers a compile-time assertion otherwise.
     */
    template <typename Seq, typename N>
    struct at;

    //! @ingroup sequence_intrinsics
    //! Alias to `at<Seq, ulong<N>>`; provided for convenience.
    template <typename Seq, unsigned long N>
    using at_c = at<Seq, ulong<N>>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_AT_HPP
