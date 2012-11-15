/**
 * This file defines the `protect` wrapper.
 */

#ifndef MPL11_PROTECT_HPP
#define MPL11_PROTECT_HPP

namespace mpl11 {

/**
 * Prevent its argument from being recognized as a bind expression.
 */
template <typename Arg> struct protect : Arg { };

} // end namespace mpl11

#endif // !MPL11_PROTECT_HPP
