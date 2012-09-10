/**
 * This file defines the or_ metafunction.
 */

#ifndef DUCK_OR_HPP
#define DUCK_OR_HPP

#include <duck/accumulate.hpp>
#include <duck/quote.hpp>

#include <type_traits>


namespace duck {

/**
 * Compute the logical or of its arguments.
 */
namespace detail {
    template <typename T, typename U> struct or_impl;
    template <bool X, bool Y>
    struct or_impl<std::integral_constant<bool, X>,
                   std::integral_constant<bool, Y>>
        : std::integral_constant<bool, X || Y> { };
}

template <typename T, typename U, typename ...Rest>
struct or_
    : accumulate<
        quote<detail::or_impl>,
        T, U, Rest...
    >
{ };

} // end namespace duck

#endif // !DUCK_OR_HPP
