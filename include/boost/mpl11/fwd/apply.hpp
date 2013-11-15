/*!
 * @file
 * Forward declares `boost::mpl11::apply`.
 */

#ifndef BOOST_MPL11_FWD_APPLY_HPP
#define BOOST_MPL11_FWD_APPLY_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Invokes a @ref MetafunctionClass `F` with arguments `Args...`.
     *
     * If `Args...` are provided, `apply` is just a wrapper over
     * `F::apply<Args...>`. Otherwise, `apply` is either `F::apply`
     * or `F::apply<>`, depending on which expression is valid.
     *
     *
     * @note
     * If `F::apply<Args...>` (or `F::apply`) is an invalid expression, an
     * incomplete type or a type from which one can't derive, a hard error
     * is triggered.
     */
    template <typename F, typename ...Args>
    struct apply;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_APPLY_HPP
