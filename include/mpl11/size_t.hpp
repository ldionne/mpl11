/**
 * This file defines the `size_t` metatype.
 */

#ifndef MPL11_SIZE_T_HPP
#define MPL11_SIZE_T_HPP

#include <mpl11/integral_constant.hpp>

#include <cstddef>


namespace mpl11 {

template <std::size_t c>
using size_t = integral_constant<std::size_t, c>;

} // end namespace mpl11

#endif // !MPL11_SIZE_T_HPP
