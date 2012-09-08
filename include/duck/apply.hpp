/**
 * This file defines the apply metafunction.
 */

#ifndef DUCK_APPLY_HPP
#define DUCK_APPLY_HPP

#include <duck/pack.hpp>


namespace duck {

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

} // end namespace duck

#endif // !DUCK_APPLY_HPP
