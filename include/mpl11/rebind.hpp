/**
 * This file defines the rebind metafunction.
 */

#ifndef MPL11_REBIND_HPP
#define MPL11_REBIND_HPP

namespace mpl11 {

/**
 * Metafunction rebinding a template's parameters to another template.
 */
template <typename From, template <typename ...> class To> struct rebind;

template <template <typename ...> class From, typename ...Args,
          template <typename ...> class To>
struct rebind<From<Args...>, To> {
    using type = To<Args...>;
};

} // end namespace mpl11

#endif // !MPL11_REBIND_HPP
