/**
 * This file defines boolean types.
 */

#ifndef MPL11_BOOL_HPP
#define MPL11_BOOL_HPP

#include <mpl11/integral_constant.hpp>


namespace mpl11 {

template <bool b>
using bool_ = integral_constant<bool, b>;

using true_ = bool_<true>;
using false_ = bool_<false>;

} // end namespace mpl11

#endif // !MPL11_BOOL_HPP
