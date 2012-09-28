/**
 * This file defines the or_ metafunction.
 */

#ifndef DUCK_OR_HPP
#define DUCK_OR_HPP

#include <type_traits>


namespace duck {

/**
 * Compute the logical or of its arguments.
 */
namespace detail {
    template <typename T, typename ...Rest> struct or_impl;

    template <typename ...Rest>
    struct or_impl<std::false_type, Rest...> : or_impl<Rest...> { };

    template <>
    struct or_impl<std::false_type> : std::false_type { };

    template <typename ...Rest>
    struct or_impl<std::true_type, Rest...> : std::true_type { };
} // end namespace detail

template <typename T, typename U, typename ...Rest>
struct or_ : detail::or_impl<T, U, Rest...> { };

} // end namespace duck

#endif // !DUCK_OR_HPP
