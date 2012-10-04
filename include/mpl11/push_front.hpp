/**
 * This file defines the push_front metafunction.
 */

#ifndef MPL11_PUSH_FRONT_HPP
#define MPL11_PUSH_FRONT_HPP

#include <mpl11/pack.hpp>


namespace mpl11 {

/**
 * Insert a parameter to the beginning of a parameter pack.
 * Note: This metafunction works on already packed parameters.
 */
template <typename T, typename Pack> struct push_front;
template <typename T, typename ...Args>
struct push_front<T, pack<Args...>> : pack<T, Args...> { };

} // end namespace mpl11

#endif // !MPL11_PUSH_FRONT_HPP
