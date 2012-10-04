/**
 * This file defines the identity metafunction.
 */

#ifndef MPL11_IDENTITY_HPP
#define MPL11_IDENTITY_HPP

namespace mpl11 {

/**
 * Metafunction whose return type is the same as its sole parameter.
 */
template <typename T> struct identity { using type = T; };

} // end namespace mpl11

#endif // !MPL11_IDENTITY_HPP
