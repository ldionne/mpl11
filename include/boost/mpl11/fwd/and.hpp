/*!
 * @file
 * Forward declares `boost::mpl11::and_`.
 */

#ifndef BOOST_MPL11_FWD_AND_HPP
#define BOOST_MPL11_FWD_AND_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup logical_operators
     *
     * Returns `F1::type && F2::type && ...Fn::type`.
     *
     * Specifically, `mpl11::and_` returns the first `Fi::type` such that
     * `not_<Fi>::value` is `true`, or `Fn::type` if no such `Fi` exists.
     * Evaluation is done left-to-right in a short-circuit fashion, as
     * documented in @ref logical_operators.
     *
     *
     * @note
     * Custom implementations are called with `F1` and `F2`, not with
     * `F1::type` and `F2::type`.
     */
    template <typename F1, typename F2, typename ...Fn>
    struct and_;

    template <typename F1, typename F2, typename ...Fn>
    using and_t = typename and_<F1, F2, Fn...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_AND_HPP
