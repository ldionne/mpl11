/**
 * This file defines the size metafunction.
 */

#ifndef MPL11_SIZE_HPP
#define MPL11_SIZE_HPP

#include <mpl11/types.hpp>


namespace mpl11 {

/**
 * Determine the number of parameters in a parameter pack.
 */
template <typename ...T>
struct size : size_t_<sizeof...(T)> { };

} // end namespace mpl11

#endif // !MPL11_SIZE_HPP
