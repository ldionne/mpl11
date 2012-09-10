/**
 * This file defines the all_of metafunction.
 */

#ifndef DUCK_ALL_OF_HPP
#define DUCK_ALL_OF_HPP

#include <duck/and.hpp>
#include <duck/apply.hpp>

#include <type_traits>


namespace duck {

/**
 * Determine whether a metafunction class is true for all of
 * the elements in a parameter pack.
 */
template <typename F, typename ...> struct all_of;
template <typename F> struct all_of<F> : std::false_type { };
template <typename F, typename T> struct all_of<F, T> : apply<F, T> { };

template <typename F, typename T, typename ...Rest>
struct all_of<F, T, Rest...>
    : and_<
        typename apply<F, T>::type,
        typename all_of<F, Rest...>::type
    >
{ };

} // end namespace duck

#endif // !DUCK_ALL_OF_HPP
