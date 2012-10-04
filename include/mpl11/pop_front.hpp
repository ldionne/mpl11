/**
 * This file defines the pop_front metafunction.
 */

#ifndef MPL11_POP_FRONT_HPP
#define MPL11_POP_FRONT_HPP

#include <mpl11/pack.hpp>


namespace mpl11 {

/**
 * Extract the tail of a parameter pack, i.e. the pack with its first
 * parameter removed.
 *
 * If the pack is empty, nothing is done.
 */
template <typename ...T>
struct pop_front { using type = pack<T...>; };

template <typename T, typename ...Tail>
struct pop_front<T, Tail...> { using type = pack<Tail...>; };

} // end namespace mpl11

#endif // !MPL11_POP_FRONT_HPP
