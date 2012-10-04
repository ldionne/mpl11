/**
 * This file defines the @em eval_if metafunction.
 */

#ifndef MPL11_EVAL_IF_HPP
#define MPL11_EVAL_IF_HPP

#include <mpl11/if.hpp>


namespace mpl11 {

/**
 * Evaluate one of its two nullary-metafunction arguments depending on the
 * value of @p C.
 */
template <typename C, typename T, typename F>
struct eval_if : if_<C, T, F>::type { };

} // end namespace mpl11

#endif // !MPL11_EVAL_IF_HPP
