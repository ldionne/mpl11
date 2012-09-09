/**
 * This file defines the rotate_left metafunction.
 */

#ifndef DUCK_ROTATE_LEFT_HPP
#define DUCK_ROTATE_LEFT_HPP

#include <duck/pack.hpp>


namespace duck {

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

} // end namespace duck

#endif // !DUCK_ROTATE_LEFT_HPP
