/**
 * This file defines the `int_` metatype.
 */

#ifndef MPL11_INT_HPP
#define MPL11_INT_HPP

#include <mpl11/integral_constant.hpp>


namespace mpl11 {

template <int c>
using int_ = integral_constant<int, c>;

} // end namespace mpl11

#endif // !MPL11_INT_HPP
