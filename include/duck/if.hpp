/**
 * This file defines the if_ metafunction.
 */

#ifndef DUCK_IF_HPP
#define DUCK_IF_HPP

#include <type_traits>


namespace duck {

/**
 * Expand to @p False when @p Bool is std::false_type,
 * and to @p True otherwise.
 */
template <typename Bool, typename True, typename False>
struct  if_ { using type = True; };

template <typename True, typename False>
struct if_<std::false_type, True, False> { using type = False; };

} // end namespace duck

#endif // !DUCK_IF_HPP
