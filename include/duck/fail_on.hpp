/**
 * This file defines the @em fail_on helper.
 */

#ifndef DUCK_FAIL_ON_HPP
#define DUCK_FAIL_ON_HPP

namespace duck {

/**
 * Trigger an error when instantiated with any type @em T. This is useful to
 * receive a diagnostic from the compiler when debugging.
 *
 * Note: This metafunction relies on the fact that the member below is not
 *       found inside @em T, which is very unlikely given its name.
 */
template <typename T>
using fail_on = typename T::this_error_was_triggered_on_purpose_;

} // end namespace duck

#endif // !DUCK_FAIL_ON_HPP
