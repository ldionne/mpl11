/**
 * This file defines the eval metafunction.
 */

#ifndef DUCK_EVAL_HPP
#define DUCK_EVAL_HPP

#include <type_traits>


namespace duck {

/**
 * Metafunction evaluating its argument, which must be a metafunction.
 */
template <typename F>
struct eval {
    using type = typename F::type;
};

} // end namespace duck

#endif // !DUCK_EVAL_HPP
