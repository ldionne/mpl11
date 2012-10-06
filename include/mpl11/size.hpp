/**
 * This file defines the size metafunction.
 */

#ifndef MPL11_SIZE_HPP
#define MPL11_SIZE_HPP

#include <cstddef>
#include <type_traits>


namespace mpl11 {

/**
 * Determine the number of parameters in a parameter pack.
 */
template <typename ...T>
struct size {
    using type = std::integral_constant<std::size_t, sizeof...(T)>;
    static auto const value = type::value;
};

} // end namespace mpl11

#endif // !MPL11_SIZE_HPP
