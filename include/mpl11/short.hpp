/**
 * This file defines the `short_` metatype.
 */

#ifndef MPL11_SHORT_HPP
#define MPL11_SHORT_HPP

#include <mpl11/integral_constant.hpp>


namespace mpl11 {

template <short c>
using short_ = integral_constant<short, c>;

} // end namespace mpl11

#endif // !MPL11_SHORT_HPP
