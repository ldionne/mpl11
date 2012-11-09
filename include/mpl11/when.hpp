/**
 * This file defines the when metafunction.
 */

#ifndef MPL11_WHEN_HPP
#define MPL11_WHEN_HPP

#include <mpl11/types.hpp>


namespace mpl11 {

/**
 * Expand to an invalid type when @p Bool is false_, and to @p T otherwise.
 */
template <typename Bool, typename T> struct when;

template <typename Expr, Expr expr, typename T>
struct when<integral_constant<Expr, expr>, T>
    : when<bool_<expr>, T>
{ };

template <typename T>
struct when<true_, T> { using type = T; };

template <typename T>
struct when<false_, T> { };

} // end namespace mpl11

#endif // !MPL11_WHEN_HPP
