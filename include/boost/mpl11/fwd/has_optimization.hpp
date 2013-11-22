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
     * Returns whether a given `Optimization` is applicable to a given type.
     *
     * By default, this is equivalent to `mpl11::false_`.
     *
     *
     * @todo Document the fact that this is a Boolean `IntegralConstant`.
     */
    template <typename T, typename Optimization>
    struct has_optimization;

    template <typename T, typename Opt>
    using has_optimization_t = typename has_optimization<T, Opt>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_HAS_OPTIMIZATION_HPP
