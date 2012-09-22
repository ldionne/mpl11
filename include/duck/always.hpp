/**
 * This file defines the always metafunction class.
 */

#ifndef DUCK_ALWAYS_HPP
#define DUCK_ALWAYS_HPP

namespace duck {

/**
 * Variadic metafunction class that always returns the same type T.
 */
template <typename T>
struct always {
    template <typename ...>
    struct apply { using type = T; };
};

} // end namespace duck

#endif // !DUCK_ALWAYS_HPP
