/**
 * This file defines the cast metafunction to cast metatypes.
 */

#ifndef MPL11_CAST_HPP
#define MPL11_CAST_HPP

#include <mpl11/integral_constant.hpp>


namespace mpl11 {

/**
 * Metafunction to cast a metatype `From` to a metatype `To`.
 */
template <typename To, typename From> struct cast;

/**
 * Specialization of the `cast` metafunction for integral constants.
 * It allows us to use something like `cast<bool, int_<2>>` to obtain `true_`.
 */
template <typename To, typename From, From from>
struct cast<To, integral_constant<From, from>>
    : integral_constant<To, static_cast<To>(from)>
{ };

} // end namespace mpl11

#endif // !MPL11_CAST_HPP
