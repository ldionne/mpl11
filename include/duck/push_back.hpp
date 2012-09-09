/**
 * This file defines the push_back metafunction.
 */

#ifndef DUCK_PUSH_BACK_HPP
#define DUCK_PUSH_BACK_HPP

#include <duck/pack.hpp>


namespace duck {

/**
 * Insert a parameter to the end of a parameter pack.
 * Note: This metafunction works on already packed parameters.
 */
template <typename T, typename Pack> struct push_back;
template <typename T, typename ...Args>
struct push_back<T, pack<Args...>> : pack<Args..., T> { };

} // end namespace duck

#endif // !DUCK_PUSH_BACK_HPP
