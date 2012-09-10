/**
 * This file defines the identity metafunction.
 */

#ifndef DUCK_IDENTITY_HPP
#define DUCK_IDENTITY_HPP

namespace duck {

/**
 * Metafunction whose return type is the same as its sole parameter.
 */
template <typename T> struct identity { using type = T; };

} // end namespace duck

#endif // !DUCK_IDENTITY_HPP
