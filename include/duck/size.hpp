/**
 * This file defines the size metafunction.
 */

#ifndef DUCK_SIZE_HPP
#define DUCK_SIZE_HPP

#include <cstddef>


namespace duck {

/**
 * Determine the number of parameters in a parameter pack.
 */
namespace detail {
    template <std::size_t, typename ...> struct size_impl;

    template <std::size_t acc> struct size_impl<acc> {
        static constexpr std::size_t value = acc;
    };

    template <std::size_t acc, typename T, typename ...Rest>
    struct size_impl<acc, T, Rest...> : size_impl<acc + 1, Rest...> { };
} // end namespace detail

template <typename ...T>
using size = detail::size_impl<0, T...>;


namespace test {

static_assert(size<>::value == 0, "");
static_assert(size<int>::value == 1, "");
static_assert(size<float, char, void>::value == 3, "");

} // end namespace test

} // end namespace duck

#endif // !DUCK_SIZE_HPP
