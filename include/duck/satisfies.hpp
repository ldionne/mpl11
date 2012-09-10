/**
 * This file defines the satisfies metafunction.
 */

#ifndef DUCK_SATISFIES_HPP
#define DUCK_SATISFIES_HPP

#include <duck/all_of.hpp>
#include <duck/apply.hpp>
#include <duck/bind.hpp>
#include <duck/placeholders.hpp>
#include <duck/quote.hpp>
#include <duck/rotate_right.hpp>


namespace duck {

/**
 * Determine whether a type satisfies a sequence of concepts
 * in the form of metafunction classes.
 */
namespace detail {
    template <typename T, typename ...Concepts>
    struct satisfies_impl
        : all_of<
            bind<_1, T>,
            Concepts...
        >
    { };
}
template <typename ...ConceptsAndT>
struct satisfies
    : apply_pack<
        quote<detail::satisfies_impl>,
        typename rotate_right<ConceptsAndT...>::type
    >
{ };

} // end namespace duck

#endif // !DUCK_SATISFIES_HPP
