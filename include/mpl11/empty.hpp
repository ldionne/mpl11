/**
 * This file defines the empty metafunction.
 */

#ifndef MPL11_EMPTY_HPP
#define MPL11_EMPTY_HPP

#include <type_traits>


namespace mpl11 {

/**
 * Determine whether a parameter pack is empty.
 */
template <typename ...> struct empty { using type = std::false_type; };
template <> struct empty<> { using type = std::true_type; };

} // end namespace mpl11

#endif // !MPL11_EMPTY_HPP
