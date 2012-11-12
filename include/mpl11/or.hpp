/**
 * This file defines the or_ metafunction.
 */

#ifndef MPL11_OR_HPP
#define MPL11_OR_HPP

#include <mpl11/bool.hpp>
#include <mpl11/cast.hpp>


namespace mpl11 {

/**
 * Compute the logical or of its arguments.
 * Its arguments must be metafunctions and are short-circuited when possible.
 */
namespace detail {
    template <typename T, typename ...Rest>
    struct or_impl
        : or_impl<typename cast<bool, typename T::type>::type, Rest...>
    { };

    template <typename ...Rest>
    struct or_impl<false_, Rest...> : or_impl<Rest...> { };

    template <>
    struct or_impl<false_> : false_ { };

    template <typename ...Rest>
    struct or_impl<true_, Rest...> : true_ { };
} // end namespace detail

template <typename T, typename U, typename ...Rest>
struct or_ : detail::or_impl<T, U, Rest...> { };

} // end namespace mpl11

#endif // !MPL11_OR_HPP
