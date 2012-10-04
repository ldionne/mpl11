/**
 * This file defines the pop_back metafunction.
 */

#ifndef MPL11_POP_BACK_HPP
#define MPL11_POP_BACK_HPP

#include <mpl11/pack.hpp>


namespace mpl11 {

/**
 * Extract the head of a parameter pack, i.e. the pack with its last
 * parameter removed.
 *
 * If the pack is empty, nothing is done.
 */
template <typename ...> struct pop_back;

template <>
struct pop_back<> { using type = pack<>; };

template <typename T>
struct pop_back<T> : pop_back<> { };

template <typename Head, typename ...Tail>
struct pop_back<Head, Tail...>
    : pop_back<pack<Head>, pack<Tail...>> { };

template <typename ...Head, typename Tail>
struct pop_back<pack<Head...>, pack<Tail>>
{ using type = pack<Head...>; };

template <typename ...Head, typename T, typename ...Tail>
struct pop_back<pack<Head...>, pack<T, Tail...>>
    : pop_back<pack<Head..., T>, pack<Tail...>> { };

} // end namespace mpl11

#endif // !MPL11_POP_BACK_HPP
