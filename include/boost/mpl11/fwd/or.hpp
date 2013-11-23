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
     * Specifically, `mpl11::or_` returns the first `Fi::type` such that
     * `not_<Fi>::value` is `false`, or `Fn::type` if no such `Fi` exists.
     * Evaluation is done left-to-right in a short-circuit fashion, as
     * documented in @ref logical_operators.
     *
     *
     * @note
     * Custom implementations are called with `F1` and `F2`, not with
     * `F1::type` and `F2::type`.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct or_;

    template <typename F1, typename F2, typename ...Fn>
    using or_t = typename or_<F1, F2, Fn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_OR_HPP
