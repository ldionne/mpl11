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
     * Invokes a @ref LambdaExpression `F` with arguments `Args...`.
     *
     *
     * @todo
     * Decide what to do with lambda expressions vs metafunction classes and
     * the object system.
     */
    template <typename F, typename ...Args>
    struct apply;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_APPLY_HPP
