/**
 * This file defines the pack template.
 */

#ifndef DUCK_PACK_HPP
#define DUCK_PACK_HPP

namespace duck {

/**
 * Template used to represent a parameter pack.
 * This is useful when we want to deduce the parameters in a pack.
 */
template <typename ...> struct pack { };

} // end namespace duck

#endif // !DUCK_PACK_HPP
