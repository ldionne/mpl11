/**
 * This file defines the back metafunction.
 */

#ifndef DUCK_BACK_HPP
#define DUCK_BACK_HPP

namespace duck {

/**
 * Extract the last parameter of a parameter pack.
 */
template <typename ...> struct back;

template <typename T>
struct back<T> { using type = T; };

template <typename T, typename ...Rest>
struct back<T, Rest...> : back<Rest...> { };

} // end namespace duck

#endif // !DUCK_BACK_HPP
