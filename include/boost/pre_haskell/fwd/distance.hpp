/*!
 * @file
 * Forward declares `boost::mpl11::distance`.
 */

#ifndef BOOST_MPL11_FWD_DISTANCE_HPP
#define BOOST_MPL11_FWD_DISTANCE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup iterator_intrinsics
     *
     * Returns the distance between `First` and `Last`.
     */
    template <typename First, typename Last>
    struct distance;

    template <typename First, typename Last>
    using distance_t = typename distance<First, Last>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_DISTANCE_HPP
