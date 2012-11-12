/**
 * This file defines the `long_` metatype.
 */

#ifndef MPL11_LONG_HPP
#define MPL11_LONG_HPP

#include <mpl11/integral_constant.hpp>


namespace mpl11 {

template <long c>
using long_ = integral_constant<long, c>;

} // end namespace mpl11

#endif // !MPL11_LONG_HPP
