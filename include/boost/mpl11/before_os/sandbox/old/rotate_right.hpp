/**
 * This file defines the rotate_right metafunction.
 */

#ifndef MPL11_ROTATE_RIGHT_HPP
#define MPL11_ROTATE_RIGHT_HPP

#include <mpl11/back.hpp>
#include <mpl11/pack.hpp>
#include <mpl11/pop_back.hpp>


namespace mpl11 {

/**
 * Perform a rotation of the parameters in a parameter
 * pack of one element to the right.
 *
 * If the pack is empty, nothing is done.
 */
template <typename ...T>
struct rotate_right
    : rotate_right<
        typename back<T...>::type,
        typename pop_back<T...>::type
    >
{ };

template <>
struct rotate_right<> : pack<> { };

template <typename Head, typename ...Tail>
struct rotate_right<Head, pack<Tail...>> : pack<Head, Tail...> { };

} // end namespace mpl11

#endif // !MPL11_ROTATE_RIGHT_HPP
