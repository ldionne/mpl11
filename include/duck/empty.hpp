/**
 * This file defines the empty metafunction.
 */

#ifndef DUCK_EMPTY_HPP
#define DUCK_EMPTY_HPP

#include <type_traits>


namespace duck {

/**
 * Determine whether a parameter pack is empty.
 */
template <typename ...> struct empty : std::false_type { };
template <> struct empty<> : std::true_type { };


namespace test {

static_assert(!empty<int>::value, "");
static_assert(!empty<int, float, char>::value, "");
static_assert(empty<>::value, "");

} // end namespace test

} // end namespace duck

#endif // !DUCK_EMPTY_HPP
