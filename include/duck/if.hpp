/**
 * This file defines the if_ metafunction.
 */

#ifndef DUCK_IF_HPP
#define DUCK_IF_HPP

#include <duck/bool.hpp>


namespace duck {

/**
 * Expand to @p False when @p Bool is false_, and to @p True otherwise.
 */
template <typename Bool, typename True, typename False>
struct  if_ { using type = True; };

template <typename True, typename False>
struct if_<false_, True, False> { using type = False; };

} // end namespace duck

#endif // !DUCK_IF_HPP
