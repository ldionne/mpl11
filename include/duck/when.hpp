/**
 * This file defines the when metafunction.
 */

#ifndef DUCK_WHEN_HPP
#define DUCK_WHEN_HPP

#include <duck/bool.hpp>


namespace duck {

/**
 * Expand to an invalid type when @p Bool is false_, and to @p T otherwise.
 */
template <typename Bool, typename T>
struct when { using type = T; };

template <typename T>
struct when<false_, T> { };

} // end namespace duck

#endif // !DUCK_WHEN_HPP
