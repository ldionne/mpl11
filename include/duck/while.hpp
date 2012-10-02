/**
 * This file defines the @em while_ metafunction.
 */

#ifndef DUCK_WHILE_HPP
#define DUCK_WHILE_HPP

#include <duck/apply.hpp>
#include <duck/eval_if.hpp>
#include <duck/identity.hpp>

#include <cstddef>


namespace duck {

/**
 * Metafunction applying a metafunction class to a state until the result
 * of applying the state to a predicate is `std::false_type`.
 * The return type of the @em while_ metafunction is the last state returned
 * by the applied metafunction class.
 */
template <typename Pred, typename F, typename State>
struct while_
    : eval_if<typename apply<Pred, State>::type,
        while_<Pred, F, typename apply<F, State>::type>,
        identity<State>
    >
{ };

} // end namespace duck

#endif // !DUCK_WHILE_HPP
