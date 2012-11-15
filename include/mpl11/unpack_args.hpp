/**
 * This file defines the `unpack_args` metafunction class.
 */

#ifndef MPL11_UNPACK_ARGS_HPP
#define MPL11_UNPACK_ARGS_HPP

#include <mpl11/apply_pack.hpp>
#include <mpl11/lambda.hpp>


namespace mpl11 {

/**
 * Transform an n-ary lambda expression into an unary metafunction class
 * taking a single argument pack.
 */
template <typename F>
struct unpack_args {
    template <typename Pack>
    struct apply
        : apply_pack<typename lambda<F>::type, Pack>
    { };
};

} // end namespace mpl11

#endif // !MPL11_UNPACK_ARGS_HPP
