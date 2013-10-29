/*!
 * @file
 * Forward declares `boost::mpl11::or_`.
 */

#ifndef BOOST_MPL11_FWD_OR_HPP
#define BOOST_MPL11_FWD_OR_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup logical_operators
     *
     * Returns `F1::type || F2::type || ...Fn::type`.
     *
     *
     * @note
     * Custom implementations are called with `F1` and `F2`.
     *
     * @todo
     * Clarify the Python-like behavior of `or_`.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct or_;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_OR_HPP
