/**
 * This file defines the back metafunction.
 */

#ifndef MPL11_BACK_HPP
#define MPL11_BACK_HPP

namespace mpl11 {

/**
 * Extract the last parameter of a parameter pack.
 */
template <typename ...> struct back;

template <typename T>
struct back<T> { using type = T; };

template <typename T, typename ...Rest>
struct back<T, Rest...> : back<Rest...> { };

} // end namespace mpl11

#endif // !MPL11_BACK_HPP
