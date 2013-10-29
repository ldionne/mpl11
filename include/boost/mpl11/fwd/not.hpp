/*!
 * @file
 * Forward declares `boost::mpl11::not_`.
 */

#ifndef BOOST_MPL11_FWD_NOT_HPP
#define BOOST_MPL11_FWD_NOT_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup logical_operators
     *
     * Returns `!F::type`.
     *
     *
     * @note
     * Custom implementations are called with `F::type` instead of `F`.
     *
     * @todo
     * Make it clearer that `not_` is a boolean `IntegralConstant`.
     */
    template <typename F>
    struct not_;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NOT_HPP
