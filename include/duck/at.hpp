/**
 * This file defines the at metafunction.
 */

#ifndef DUCK_AT_HPP
#define DUCK_AT_HPP

#include <duck/size.hpp>

#include <cstddef>


namespace duck {

/**
 * Extract the parameter at index @p i from a parameter pack.
 * Precondition: @p i is smaller than the number of parameters.
 */
namespace detail {
template <std::size_t, typename ...> struct at_impl;

template <typename First, typename ...Rest>
struct at_impl<0, First, Rest...> { using type = First; };

template <std::size_t i, typename First, typename ...Rest>
struct at_impl<i, First, Rest...> : at_impl<i - 1, Rest...> { };
} // end namespace detail

template <std::size_t i, typename ...Range>
struct at {
    static_assert(i < size<Range...>::value, "Index out of range.");
    using type = typename detail::at_impl<i, Range...>::type;
};

} // end namespace duck

#endif // !DUCK_AT_HPP
