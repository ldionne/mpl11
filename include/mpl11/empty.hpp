/**
 * This file defines the empty metafunction.
 */

#ifndef MPL11_EMPTY_HPP
#define MPL11_EMPTY_HPP

#include <mpl11/types.hpp>


namespace mpl11 {

/**
 * Determine whether a parameter pack is empty.
 */
template <typename ...> struct empty : false_ { };
template <> struct empty<> : true_ { };

} // end namespace mpl11

#endif // !MPL11_EMPTY_HPP
