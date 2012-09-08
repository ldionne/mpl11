/**
 * This file defines the apply metafunction.
 */

#ifndef DUCK_APPLY_HPP
#define DUCK_APPLY_HPP

namespace duck {

/**
 * Apply a metafunction class on the given arguments.
 */
template <typename F, typename ...Args>
struct apply : F::template apply<Args...> { };

} // end namespace duck

#endif // !DUCK_APPLY_HPP
