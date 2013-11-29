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
     * Creates a partially applied `MetafunctionClass` from a
     * `MetafunctionClass` `F` and a sequence of arguments.
     *
     * Specifically, `apply<partial<F, X...>, Args...>` is equivalent to
     * `apply<F, X..., Args...>`.
     */
    template <typename F, typename ...X>
    struct partial;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_PARTIAL_HPP
