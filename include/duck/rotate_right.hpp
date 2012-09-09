/**
 * This file defines the rotate_right metafunction.
 */

#ifndef DUCK_ROTATE_RIGHT_HPP
#define DUCK_ROTATE_RIGHT_HPP

#include <duck/back.hpp>
#include <duck/pack.hpp>
#include <duck/pop_back.hpp>


namespace duck {

/**
 * Perform a rotation of the parameters in a parameter
 * pack of one element to the right.
 *
 * If the pack is empty, nothing is done.
 */
template <typename ...T>
struct rotate_right
    : rotate_right<
        typename back<T...>::type,
        typename pop_back<T...>::type
    >
{ };

template <>
struct rotate_right<> : pack<> { };

template <typename Head, typename ...Tail>
struct rotate_right<Head, pack<Tail...>> : pack<Head, Tail...> { };

} // end namespace duck

#endif // !DUCK_ROTATE_RIGHT_HPP
