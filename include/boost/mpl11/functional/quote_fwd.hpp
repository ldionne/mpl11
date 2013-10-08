/*!
 * @file
 * Forward declares `boost::mpl11::quote`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_QUOTE_FWD_HPP
#define BOOST_MPL11_FUNCTIONAL_QUOTE_FWD_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup functional
     *
     * Higher-order primitive wrapping a @ref Metafunction to create a
     * corresponding @ref MetafunctionClass.
     *
     * Specifically, `quote<F>::apply<Args...>::type` is equivalent to
     * `F<Args...>::type` if that expression is valid, and `F<Args...>`
     * otherwise.
     */
    template <template <typename ...> class F>
    struct quote;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_QUOTE_FWD_HPP
