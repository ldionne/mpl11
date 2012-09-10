/**
 * This file defines the and_ metafunction.
 */

#ifndef DUCK_AND_HPP
#define DUCK_AND_HPP

#include <duck/accumulate.hpp>
#include <duck/quote.hpp>

#include <type_traits>


namespace duck {

/**
 * Compute the logical and of its arguments.
 */
namespace detail {
    template <typename T, typename U> struct and_impl;
    template <bool X, bool Y>
    struct and_impl<std::integral_constant<bool, X>,
                    std::integral_constant<bool, Y>>
        : std::integral_constant<bool, X && Y> { };
}

template <typename T, typename U, typename ...Rest>
struct and_
    : accumulate<
        quote<detail::and_impl>,
        T, U, Rest...
    >
{ };

} // end namespace duck

#endif // !DUCK_AND_HPP
