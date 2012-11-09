/**
 * This file defines the any_of metafunction.
 */

#ifndef MPL11_ANY_OF_HPP
#define MPL11_ANY_OF_HPP

#include <mpl11/apply.hpp>
#include <mpl11/bool.hpp>
#include <mpl11/or.hpp>


namespace mpl11 {

/**
 * Determine whether a metafunction class is true for any of
 * the elements in a parameter pack.
 */
template <typename F, typename ...> struct any_of;
template <typename F> struct any_of<F> : false_ { };
template <typename F, typename T> struct any_of<F, T> : apply<F, T> { };

template <typename F, typename T, typename ...Rest>
struct any_of<F, T, Rest...>
    : or_<
        apply<F, T>,
        any_of<F, Rest...>
    >
{ };

} // end namespace mpl11

#endif // !MPL11_ANY_OF_HPP
