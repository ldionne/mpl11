/**
 * This file defines the push_back metafunction.
 */

#ifndef MPL11_PUSH_BACK_HPP
#define MPL11_PUSH_BACK_HPP

#include <mpl11/pack.hpp>


namespace mpl11 {

/**
 * Insert a parameter to the end of a parameter pack.
 * Note: This metafunction works on already packed parameters.
 */
template <typename T, typename Pack> struct push_back;
template <typename T, typename ...Args>
struct push_back<T, pack<Args...>> : pack<Args..., T> { };

} // end namespace mpl11

#endif // !MPL11_PUSH_BACK_HPP
