/**
 * This file defines the and_ metafunction.
 */

#ifndef DUCK_AND_HPP
#define DUCK_AND_HPP

#include <type_traits>


namespace duck {

/**
 * Compute the logical and of its arguments.
 */
namespace detail {
    template <typename T, typename ...Rest> struct and_impl;

    template <typename ...Rest>
    struct and_impl<std::true_type, Rest...> : and_impl<Rest...> { };

    template <>
    struct and_impl<std::true_type> : std::true_type { };

    template <typename ...Rest>
    struct and_impl<std::false_type, Rest...> : std::false_type { };
} // end namespace detail

template <typename T, typename U, typename ...Rest>
struct and_ : detail::and_impl<T, U, Rest...> { };

} // end namespace duck

#endif // !DUCK_AND_HPP
