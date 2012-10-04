/**
 * This file defines the or_ metafunction.
 */

#ifndef MPL11_OR_HPP
#define MPL11_OR_HPP

#include <type_traits>


namespace mpl11 {

/**
 * Compute the logical or of its arguments.
 * Its arguments must be metafunctions and are short-circuited when possible.
 */
namespace detail {
    template <typename T, typename ...Rest>
    struct or_impl : or_impl<typename T::type, Rest...> { };

    template <typename ...Rest>
    struct or_impl<std::false_type, Rest...> : or_impl<Rest...> { };

    template <>
    struct or_impl<std::false_type> : std::false_type { };

    template <typename ...Rest>
    struct or_impl<std::true_type, Rest...> : std::true_type { };
} // end namespace detail

template <typename T, typename U, typename ...Rest>
struct or_ : detail::or_impl<T, U, Rest...> { };

} // end namespace mpl11

#endif // !MPL11_OR_HPP
