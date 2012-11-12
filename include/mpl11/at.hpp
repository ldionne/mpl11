/**
 * This file defines the at metafunction.
 */

#ifndef MPL11_AT_HPP
#define MPL11_AT_HPP

#include <mpl11/size.hpp>

#include <cstddef>


namespace mpl11 {

namespace detail {
    template <std::size_t counter, typename ...> struct at_impl;

    template <typename First, typename ...Rest>
    struct at_impl<0, First, Rest...> {
        using type = First;
    };

    template <std::size_t pos, typename First, typename ...Rest>
    struct at_impl<pos, First, Rest...>
        : at_impl<pos - 1, Rest...>
    { };
} // end namespace detail

/**
 * Extract the parameter at index @p pos from a parameter pack.
 * Precondition: @p pos is smaller than the number of parameters.
 */
template <std::size_t pos, typename ...Range>
struct at_c {
    static_assert(pos < size<Range...>::value, "Index out of range.");
    using type = typename detail::at_impl<pos, Range...>::type;
};

template <typename Pos, typename ...Range>
struct at
    : at_c<Pos::value, Range...>
{ };

} // end namespace mpl11

#endif // !MPL11_AT_HPP
