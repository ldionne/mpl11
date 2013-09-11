/*!
 * @file
 * Defines `boost::mpl11::apply`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_APPLY_HPP
#define BOOST_MPL11_FUNCTIONAL_APPLY_HPP

#include <boost/mpl11/functional/apply_wrap.hpp>
#include <boost/mpl11/functional/lambda.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup functional
     *
     * Invokes a `LambdaExpression` `F` with arguments `Args...`.
     *
     * Equivalent to `apply_wrap<lambda<F>::type, Args...>`.
     */
    template <typename F, typename ...Args>
    struct apply
        : apply_wrap<typename lambda<F>::type, Args...>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_APPLY_HPP
