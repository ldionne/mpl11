/*!
 * @file
 * Forward declares `boost::mpl11::partial`.
 */

#ifndef BOOST_MPL11_FWD_PARTIAL_HPP
#define BOOST_MPL11_FWD_PARTIAL_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunction_classes
     *
     * Partially applies a metafunction class.
     *
     * Specifically, `apply<partial<F, X...>, Args...>` is equivalent to
     * `apply<F, X..., Args...>`.
     *
     *
     * @note
     * `partial` is specialized for `quote` and `into` so that patterns like
     * `partial<quote<equal>, X...>` are as efficient as writing a custom
     * metafunction class.
     */
    template <typename F, typename ...X>
    struct partial;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_PARTIAL_HPP
