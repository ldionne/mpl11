/*!
 * @file
 * Forward declares `boost::mpl11::has_optimization`.
 */

#ifndef BOOST_MPL11_FWD_HAS_OPTIMIZATION_HPP
#define BOOST_MPL11_FWD_HAS_OPTIMIZATION_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Boolean `Integral` representing whether the given `Optimization` is
     * applicable to the given type.
     *
     * By default, this is equivalent to `false_`.
     */
    template <typename T, typename Optimization>
    struct has_optimization;

    template <typename T, typename Opt>
    using has_optimization_t = typename has_optimization<T, Opt>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_HAS_OPTIMIZATION_HPP
