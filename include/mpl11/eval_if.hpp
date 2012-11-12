/**
 * This file defines the @em eval_if metafunction.
 */

#ifndef MPL11_EVAL_IF_HPP
#define MPL11_EVAL_IF_HPP

#include <mpl11/if.hpp>


namespace mpl11 {

/**
 * Evaluate one of its two nullary-metafunction arguments depending on the
 * value of @p Cond.
 */
template <typename Cond, typename True, typename False>
struct eval_if
    : if_<Cond, True, False>::type
{ };

template <bool cond, typename True, typename False>
struct eval_if_c
    : if_c<cond, True, False>::type
{ };

} // end namespace mpl11

#endif // !MPL11_EVAL_IF_HPP
