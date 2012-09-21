/**
 * This file defines the arg metafunction class.
 */

#ifndef DUCK_ARG_HPP
#define DUCK_ARG_HPP

#include <duck/at.hpp>

#include <cstddef>


namespace duck {

/**
 * Metafunction class returning the nth of its arguments.
 */
template <std::size_t n>
struct arg {
    template <typename ...Args>
    struct apply : at<n - 1, Args...> { };
};

} // end namespace duck

#endif // !DUCK_ARG_HPP
