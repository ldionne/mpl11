/*!
 * @file
 * Forward declares `boost::mpl11::apply`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_APPLY_FWD_HPP
#define BOOST_MPL11_FUNCTIONAL_APPLY_FWD_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup functional
     *
     * Invokes a @ref LambdaExpression `F` with arguments `Args...`.
     *
     * Equivalent to `apply_wrap<lambda<F>::type, Args...>`.
     */
    template <typename F, typename ...Args>
    struct apply;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_APPLY_FWD_HPP
