/**
 * This file defines the and_ metafunction.
 */

#ifndef MPL11_AND_HPP
#define MPL11_AND_HPP

#include <mpl11/types.hpp>


namespace mpl11 {

/**
 * Compute the logical and of its arguments.
 * Its arguments must be metafunctions and are short-circuited when possible.
 */
namespace detail {
    template <typename T, typename ...Rest>
    struct and_impl : and_impl<typename T::type, Rest...> { };

    template <typename ...Rest>
    struct and_impl<true_, Rest...> : and_impl<Rest...> { };

    template <>
    struct and_impl<true_> : true_ { };

    template <typename ...Rest>
    struct and_impl<false_, Rest...> : false_ { };
} // end namespace detail

template <typename T, typename U, typename ...Rest>
struct and_ : detail::and_impl<T, U, Rest...> { };

} // end namespace mpl11

#endif // !MPL11_AND_HPP
