/**
 * This file defines the front metafunction.
 */

#ifndef DUCK_FRONT_HPP
#define DUCK_FRONT_HPP

namespace duck {

/**
 * Extract the first parameter of a parameter pack.
 */
template <typename T, typename ...Rest>
struct front { using type = T; };

} // end namespace duck

#endif // !DUCK_FRONT_HPP
