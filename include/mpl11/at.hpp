/**
 * This file defines the at metafunction.
 */

#ifndef MPL11_AT_HPP
#define MPL11_AT_HPP

#include <mpl11/size.hpp>

#include <cstddef>


namespace mpl11 {

/**
 * Extract the parameter at index @p i from a parameter pack.
 * Precondition: @p i is smaller than the number of parameters.
 */
namespace detail {
template <std::size_t counter, typename ...> struct at_impl;

template <typename First, typename ...Rest>
struct at_impl<0, First, Rest...> {
    using type = First;
};

template <std::size_t pos, typename First, typename ...Rest>
struct at_impl<pos, First, Rest...>
    : at_impl<pos - 1, Rest...> { };
} // end namespace detail

template <std::size_t pos, typename ...Range>
struct at {
    static_assert(pos < size<Range...>::value, "Index out of range.");
    using type = typename detail::at_impl<pos, Range...>::type;
};

} // end namespace mpl11

#endif // !MPL11_AT_HPP
