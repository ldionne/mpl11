/*!
 * @file
 * Forward declares `boost::mpl11::compose`.
 */

#ifndef BOOST_MPL11_FWD_COMPOSE_HPP
#define BOOST_MPL11_FWD_COMPOSE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunction_classes
     *
     * Creates a `MetafunctionClass` equivalent to the composition of
     * `MetafunctionClass`es `F1`, ..., `Fn`.
     *
     * Specifically:
     *
     * - Let `f(x)` denote `apply<f, x>::type` to lighten the notation. Then,
     *   `apply<compose<F1, F2, ..., Fn>, A1, ..., An>` is equivalent
     *   to `apply<F1, F2(...Fn(A1, ..., An))>`.
     *
     * - `apply<compose<F1>, A1, ..., An>` is equivalent to
     *   `apply<F1, A1, ..., An>`.
     */
    template <typename F1, typename ...Fn>
    struct compose;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_COMPOSE_HPP