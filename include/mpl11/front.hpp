/**
 * This file defines the front metafunction.
 */

#ifndef MPL11_FRONT_HPP
#define MPL11_FRONT_HPP

namespace mpl11 {

/**
 * Extract the first parameter of a parameter pack.
 */
template <typename T, typename ...Rest>
struct front { using type = T; };

} // end namespace mpl11

#endif // !MPL11_FRONT_HPP
