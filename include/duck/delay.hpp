/**
 * This file defines the delay metafunction.
 */

#ifndef DUCK_DELAY_HPP
#define DUCK_DELAY_HPP

namespace duck {

/**
 * Template used to delay the evaluation of the template expression @p T.
 */
template <typename T> struct delay { using type = T; };

} // end namespace duck

#endif // !DUCK_DELAY_HPP
