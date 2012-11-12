/**
 * This file defines the when metafunction.
 */

#ifndef MPL11_WHEN_HPP
#define MPL11_WHEN_HPP

#include <mpl11/bool.hpp>
#include <mpl11/cast.hpp>


namespace mpl11 {

/**
 * Expand to an invalid type when @p Expr is false_, and to @p T otherwise.
 */
template <typename Expr, typename T>
struct when
    : when<typename cast<bool, Expr>::type, T>
{ };

template <typename T>
struct when<true_, T> { using type = T; };

template <typename T>
struct when<false_, T> { };

} // end namespace mpl11

#endif // !MPL11_WHEN_HPP
