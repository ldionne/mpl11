/**
 * This file defines the accumulate metafunction.
 */

#ifndef DUCK_ACCUMULATE_HPP
#define DUCK_ACCUMULATE_HPP

#include <duck/apply.hpp>


namespace duck {

/**
 * Perform the functionnal accumulation of the result of applying a
 * metafunction class on every parameter of a parameter pack.
 */
template <typename F, typename ...> struct accumulate;
template <typename F, typename T, typename U>
struct accumulate<F, T, U> : apply<F, T, U> { };

template <typename F, typename T, typename ...Rest>
struct accumulate<F, T, Rest...>
    : apply<F, T, typename accumulate<F, Rest...>::type> { };

} // end namespace duck

#endif // !DUCK_ACCUMULATE_HPP
