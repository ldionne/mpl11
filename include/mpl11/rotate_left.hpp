/**
 * This file defines the rotate_left metafunction.
 */

#ifndef MPL11_ROTATE_LEFT_HPP
#define MPL11_ROTATE_LEFT_HPP

#include <mpl11/pack.hpp>


namespace mpl11 {

/**
 * Perform a rotation of the parameters in a parameter
 * pack of one element to the left.
 *
 * If the pack is empty, nothing is done.
 */
template <typename ...ZeroOrOne>
struct rotate_left : pack<ZeroOrOne...> { };

template <typename Head, typename ...Tail>
struct rotate_left<Head, Tail...> : pack<Tail..., Head> { };

} // end namespace mpl11

#endif // !MPL11_ROTATE_LEFT_HPP
