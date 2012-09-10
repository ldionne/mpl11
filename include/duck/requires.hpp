/**
 * This file defines the requires metafunction.
 */

#ifndef DUCK_REQUIRES_HPP
#define DUCK_REQUIRES_HPP

#include <duck/all_of.hpp>
#include <duck/apply.hpp>
#include <duck/identity.hpp>
#include <duck/quote.hpp>
#include <duck/rotate_right.hpp>
#include <duck/when.hpp>

namespace duck {

/**
 * Expand to the last type in the parameter pack if all the types before it
 * are std::true_type. Otherwise, expand to an invalid type.
 *
 * This is useful to express the concept requirements of a template
 * in its declaration, much like std::enable_if does.
 */
namespace detail {
    template <typename T, typename ...Concepts>
    struct requires_impl
        : when<
            typename all_of<quote<identity>, Concepts...>::type, T
        >
    { };
}

template <typename ...ConceptsAndT>
struct requires
    : apply_pack<
        quote<detail::requires_impl>,
        typename rotate_right<ConceptsAndT...>::type
    >
{ };

} // end namespace duck

#endif // !DUCK_REQUIRES_HPP
