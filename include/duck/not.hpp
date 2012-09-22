/**
 * This file defines the not_ metafunction.
 */

#ifndef DUCK_NOT_HPP
#define DUCK_NOT_HPP

#include <type_traits>


namespace duck {

/**
 * Metafunction that negates the result of another metafunction.
 */
template <typename T> struct not_;

template <bool R>
struct not_<std::integral_constant<bool, R>> {
    using type = typename std::integral_constant<bool, !R>::type;
};

} // end namespace duck

#endif // !DUCK_NOT_HPP
