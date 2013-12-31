/*!
 * @file
 * Forward declares `boost::mpl11::first`.
 */

#ifndef BOOST_MPL11_FWD_FIRST_HPP
#define BOOST_MPL11_FWD_FIRST_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * Returns the first element of a pair.
     *
     *
     * @warning
     * In the original MPL, `mpl11::first` was a trivial metafunction
     * fetching `Pair::first`. `mpl11::first` is now an intrinsic.
     */
    template <typename Pair>
    struct first;

    template <typename Pair>
    using first_t = typename first<Pair>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FIRST_HPP
