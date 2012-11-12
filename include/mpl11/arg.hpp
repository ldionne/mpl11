/**
 * This file defines the arg metafunction class.
 */

#ifndef MPL11_ARG_HPP
#define MPL11_ARG_HPP

#include <mpl11/at.hpp>

#include <cstddef>


namespace mpl11 {

/**
 * Metafunction class returning the nth of its arguments.
 */
template <std::size_t n>
struct arg {
    template <typename ...Args>
    struct apply : at_c<n - 1, Args...> { };
};

} // end namespace mpl11

#endif // !MPL11_ARG_HPP
