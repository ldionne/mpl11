/**
 * This file defines the pack template.
 */

#ifndef MPL11_PACK_HPP
#define MPL11_PACK_HPP

namespace mpl11 {

/**
 * Template used to represent a parameter pack.
 * This is useful when we want to deduce the parameters in a pack.
 */
template <typename ...T> struct pack {
    // Note: This is to simplify usage in metafunctions
    //       so it can be inherited.
    using type = pack<T...>;
};

} // end namespace mpl11

#endif // !MPL11_PACK_HPP
