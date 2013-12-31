/*!
 * @file
 * Forward declares `boost::mpl11::quote`.
 */

#ifndef BOOST_MPL11_FWD_QUOTE_HPP
#define BOOST_MPL11_FWD_QUOTE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunction_classes
     *
     * Turns a metafunction into an equivalent metafunction class.
     *
     * Specifically, `apply<quote<F>, Args...>` is equivalent to `F<Args...>`.
     *
     *
     * @warning
     * `quote` in the original MPL used to return either `F<Args...>` or
     * `F<Args...>::%type` depending on the validity of the latter expression.
     * This is not the case anymore.
     */
    template <template <typename ...> class F>
    struct quote;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_QUOTE_HPP
