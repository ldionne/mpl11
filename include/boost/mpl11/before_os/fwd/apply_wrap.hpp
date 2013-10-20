/*!
 * @file
 * Forward declares `boost::mpl11::apply_wrap`.
 */

#ifndef BOOST_MPL11_FWD_APPLY_WRAP_HPP
#define BOOST_MPL11_FWD_APPLY_WRAP_HPP

namespace boost { namespace mpl11 {
/*!
 * @ingroup functional
 *
 * Invokes a @ref MetafunctionClass `F` with arguments `Args...`.
 *
 * `apply_wrap` is just a wrapper around `F::apply<Args...>::type` or
 * `F::apply::type`, depending on the arity of `F` as a @ref MetafunctionClass.
 *
 * If `F::apply<Args...>::type` (and `F::apply::type` if `Args...` is empty)
 * are invalid expressions, `apply_wrap` does not have a nested type.
 *
 * @warning
 * The SFINAE-friendly behavior when `F::apply<Args...>::type` is an invalid
 * expression is a difference from the semantics of the original MPL.
 */
template <typename F, typename ...Args>
struct apply_wrap;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_APPLY_WRAP_HPP
