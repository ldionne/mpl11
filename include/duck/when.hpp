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
template <typename Bool, typename T>
struct when { using type = T; };

template <typename T>
struct when<std::false_type, T> { };

} // end namespace duck

#endif // !DUCK_WHEN_HPP
