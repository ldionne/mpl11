/**
 * This file defines the @em eval_if metafunction.
 */

#ifndef DUCK_EVAL_IF_HPP
#define DUCK_EVAL_IF_HPP

#include <duck/if.hpp>


namespace duck {

/**
 * Evaluate one of its two nullary-metafunction arguments depending on the
 * value of @p C.
 */
template <typename C, typename T, typename F>
struct eval_if : if_<C, T, F>::type { };

} // end namespace duck

#endif // !DUCK_EVAL_IF_HPP
