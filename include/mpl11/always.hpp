/**
 * This file defines the always metafunction class.
 */

#ifndef MPL11_ALWAYS_HPP
#define MPL11_ALWAYS_HPP

namespace mpl11 {

/**
 * Variadic metafunction class that always returns the same type T.
 */
template <typename T>
struct always {
    template <typename ...>
    struct apply { using type = T; };
};

} // end namespace mpl11

#endif // !MPL11_ALWAYS_HPP
