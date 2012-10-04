/**
 * This file defines the when metafunction.
 */

#ifndef MPL11_WHEN_HPP
#define MPL11_WHEN_HPP

#include <type_traits>


namespace mpl11 {

/**
 * Expand to an invalid type when @p Bool is std::false_type,
 * and to @p T otherwise.
 */
template <typename Bool, typename T> struct when;

template <bool Expr, typename T>
struct when<std::integral_constant<bool, Expr>, T> { using type = T; };

template <typename T>
struct when<std::integral_constant<bool, false>, T> { };

} // end namespace mpl11

#endif // !MPL11_WHEN_HPP
