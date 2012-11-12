/**
 * This file defines the `apply` metafunction.
 */

#ifndef MPL11_APPLY_HPP
#define MPL11_APPLY_HPP

#include <mpl11/pack.hpp>


namespace mpl11 {

/**
 * Apply a metafunction class on the given arguments.
 */
template <typename F, typename ...Args>
struct apply
    : F::template apply<Args...>
{ };

} // end namespace mpl11

#include <mpl11/apply_pack.hpp> // For backward compatibility

#endif // !MPL11_APPLY_HPP
