/**
 * This file defines the `char_` metatype.
 */

#ifndef MPL11_CHAR_HPP
#define MPL11_CHAR_HPP

#include <mpl11/integral_constant.hpp>


namespace mpl11 {

template <char c>
using char_ = integral_constant<char, c>;

} // end namespace mpl11

#endif // !MPL11_CHAR_HPP
