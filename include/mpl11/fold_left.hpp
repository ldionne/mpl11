/**
 * This file defines the @em fold_left metafunction.
 */

#ifndef MPL11_FOLD_LEFT_HPP
#define MPL11_FOLD_LEFT_HPP

#include <mpl11/apply.hpp>


namespace mpl11 {

/**
 * Take the @p Initial argument and the first element of the parameter pack
 * and apply a function to them, then feed the function with this result and
 * so on.
 */
template <typename F, typename ...> struct fold_left;
template <typename F, typename Initial, typename Last>
struct fold_left<F, Initial, Last> : apply<F, Initial, Last> { };

template <typename F, typename Initial, typename Head, typename ...Tail>
struct fold_left<F, Initial, Head, Tail...>
    : fold_left<F, typename apply<F, Initial, Head>::type, Tail...> { };

} // end namespace mpl11

#endif // !MPL11_FOLD_LEFT_HPP
