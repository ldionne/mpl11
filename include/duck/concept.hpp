/**
 * This file implements the concept metafunction.
 */

#ifndef DUCK_CONCEPT_HPP
#define DUCK_CONCEPT_HPP

#include <duck/all_of.hpp>


namespace duck {

namespace detail {
    struct eval {
        template <typename T>
        struct apply { using type = typename T::type; };
    };
}

/**
 * Evaluate a sequence of metafunctions and return whether they are all true.
 */
template <typename ...Predicates>
struct concept
    : all_of<detail::eval, Predicates...>
{ };

} // end namespace duck

#endif // !DUCK_CONCEPT_HPP
