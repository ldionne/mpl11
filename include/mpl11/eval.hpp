/**
 * This file defines the eval metafunction.
 */

#ifndef MPL11_EVAL_HPP
#define MPL11_EVAL_HPP

namespace mpl11 {

/**
 * Metafunction evaluating its argument, which must be a metafunction.
 */
template <typename F>
struct eval {
    using type = typename F::type;
};

} // end namespace mpl11

#endif // !MPL11_EVAL_HPP
