/**
 * This file defines the `apply_pack` metafunction.
 */

#ifndef MPL11_APPLY_PACK_HPP
#define MPL11_APPLY_PACK_HPP

#include <mpl11/apply.hpp>
#include <mpl11/pack.hpp>


namespace mpl11 {

/**
 * Apply a metafunction class on a pack of arguments.
 */
template <typename F, typename Pack> struct apply_pack;
template <typename F, typename ...Args>
struct apply_pack<F, pack<Args...>>
    : apply<F, Args...>
{ };

} // end namespace mpl11

#endif // !MPL11_APPLY_PACK_HPP
