/**
 * This file defines the @em fold_right metafunction.
 */

#ifndef MPL11_FOLD_RIGHT_HPP
#define MPL11_FOLD_RIGHT_HPP

#include <mpl11/apply.hpp>


namespace mpl11 {

/**
 * Take the @p Initial argument and the last element of the parameter pack
 * and apply a function to them, then feed the function with the penultimate
 * element and this result, and so on.
 */
template <typename F, typename ...> struct fold_right;
template <typename F, typename Initial, typename Last>
struct fold_right<F, Initial, Last> : apply<F, Last, Initial> { };

template <typename F, typename Initial, typename Head, typename ...Tail>
struct fold_right<F, Initial, Head, Tail...>
    : apply<F, Head, typename fold_right<F, Initial, Tail...>::type> { };

} // end namespace mpl11

#endif // !MPL11_FOLD_RIGHT_HPP
