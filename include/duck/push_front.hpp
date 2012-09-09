/**
 * This file defines the push_front metafunction.
 */

#ifndef DUCK_PUSH_FRONT_HPP
#define DUCK_PUSH_FRONT_HPP

#include <duck/pack.hpp>


namespace duck {

/**
 * Insert a parameter to the beginning of a parameter pack.
 * Note: This metafunction works on already packed parameters.
 */
template <typename T, typename Pack> struct push_front;
template <typename T, typename ...Args>
struct push_front<T, pack<Args...>> : pack<T, Args...> { };

} // end namespace duck

#endif // !DUCK_PUSH_FRONT_HPP
