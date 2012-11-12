/**
 * This file defines the `void_` metatype.
 */

#ifndef MPL11_VOID_HPP
#define MPL11_VOID_HPP

#include <mpl11/bool.hpp>


namespace mpl11 {

/**
 * Type representing "nothing".
 */
struct void_ {
    using type = void_;
};

template <typename T> struct is_void : false_ { };
template <> struct is_void<void_> : true_ { };

} // end namespace mpl11

#endif // !MPL11_VOID_HPP
