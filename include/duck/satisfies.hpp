/**
 * This file defines the satisfies metafunction.
 */

#ifndef DUCK_SATISFIES_HPP
#define DUCK_SATISFIES_HPP

#include <duck/and.hpp>
#include <duck/apply.hpp>


namespace duck {

/**
 * Determine whether a type satisfies a sequence of concepts
 * in the form of metafunction classes.
 */
template <typename T, typename ...> struct satisfies;
template <typename T, typename Concept>
struct satisfies<T, Concept> : apply<Concept, T>::type { };

template <typename T, typename Concept, typename ...Rest>
struct satisfies<T, Concept, Rest...>
    : and_<
        typename satisfies<T, Concept>::type,
        typename satisfies<T, Rest...>::type
    >
{ };

} // end namespace duck

#endif // !DUCK_SATISFIES_HPP
