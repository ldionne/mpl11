/**
 * This file defines the not_ metafunction.
 */

#ifndef MPL11_NOT_HPP
#define MPL11_NOT_HPP

#include <type_traits>


namespace mpl11 {

/**
 * Metafunction that negates the result of evaluating a metafunction given
 * as argument.
 */
template <typename T>
struct not_ : not_<typename T::type> { };

template <>
struct not_<std::true_type> : std::false_type { };

template <>
struct not_<std::false_type> : std::true_type { };

} // end namespace mpl11

#endif // !MPL11_NOT_HPP
