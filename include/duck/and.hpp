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
    template <typename T, typename U>
    struct and_impl : std::integral_constant<bool, T::value && U::value> { };
}

template <typename ...> struct and_;
template <> struct and_<> : std::true_type { };

template <typename T, typename ...Rest>
struct and_<T, Rest...>
    : accumulate<
        quote<detail::and_impl>,
        std::true_type, T, Rest...
    >::type
{ };

} // end namespace duck

#endif // !DUCK_AND_HPP
