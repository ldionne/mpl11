/**
 * This file defines the any_of metafunction.
 */

#ifndef DUCK_ANY_OF_HPP
#define DUCK_ANY_OF_HPP

#include <duck/apply.hpp>
#include <duck/or.hpp>

#include <type_traits>


namespace duck {

/**
 * Determine whether a metafunction class is true for any of
 * the elements in a parameter pack.
 */
template <typename F, typename ...> struct any_of;
template <typename F> struct any_of<F> : std::false_type { };
template <typename F, typename T> struct any_of<F, T> : apply<F, T> { };

template <typename F, typename T, typename ...Rest>
struct any_of<F, T, Rest...>
    : or_<
        apply<F, T>,
        any_of<F, Rest...>
    >
{ };

} // end namespace duck

#endif // !DUCK_ANY_OF_HPP
