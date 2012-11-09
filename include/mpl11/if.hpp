/**
 * This file defines the if_ metafunction.
 */

#ifndef MPL11_IF_HPP
#define MPL11_IF_HPP

#include <mpl11/types.hpp>


namespace mpl11 {

/**
 * Expand to @p False when @p Bool is false_, and to @p True otherwise.
 */
template <typename Bool, typename True, typename False> struct if_;

template <typename T, T expr, typename True, typename False>
struct if_<integral_constant<T, expr>, True, False>
    : if_<bool_<expr>, True, False>
{ };

template <typename True, typename False>
struct if_<true_, True, False> {
    using type = True;
};

template <typename True, typename False>
struct if_<false_, True, False> {
    using type = False;
};

} // end namespace mpl11

#endif // !MPL11_IF_HPP
