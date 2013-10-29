/*!
 * @file
 * Forward declares `boost::mpl11::IntegralConstant`.
 */

#ifndef BOOST_MPL11_FWD_INTEGRAL_CONSTANT_HPP
#define BOOST_MPL11_FWD_INTEGRAL_CONSTANT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup mixins
     *
     * Mixin for integral constant wrappers.
     *
     *
     * @todo Document this concept properly.
     */
    template <template <typename T, T v> class integral_constant>
    struct IntegralConstant;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTEGRAL_CONSTANT_HPP
