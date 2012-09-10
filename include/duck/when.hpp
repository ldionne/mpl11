/**
 * This file defines the when metafunction.
 */

#ifndef DUCK_WHEN_HPP
#define DUCK_WHEN_HPP

#include <type_traits>


namespace duck {

/**
 * Expand to an invalid type when @p Bool is std::false_type,
 * and to @p T otherwise.
 */
template <typename Bool, typename T> struct when;

template <bool Expr, typename T>
struct when<std::integral_constant<bool, Expr>, T> { using type = T; };

template <typename T>
struct when<std::integral_constant<bool, false>, T> { };

} // end namespace duck

#endif // !DUCK_WHEN_HPP
