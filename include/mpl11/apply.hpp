/**
 * This file defines the apply metafunction.
 */

#ifndef MPL11_APPLY_HPP
#define MPL11_APPLY_HPP

#include <mpl11/pack.hpp>


namespace mpl11 {

/**
 * Apply a metafunction class on the given arguments.
 */
template <typename F, typename ...Args>
struct apply : F::template apply<Args...> { };

/**
 * Apply a metafunction class on packed arguments.
 *
 * Note: We need a different metafunction because it would be impossible
 *       to call apply with packed arguments otherwise.
 */
template <typename F, typename Pack> struct apply_pack;
template <typename F, typename ...Args>
struct apply_pack<F, pack<Args...>> : apply<F, Args...> { };

} // end namespace mpl11

#endif // !MPL11_APPLY_HPP
