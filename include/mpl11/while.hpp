/**
 * This file defines the @em while_ metafunction.
 */

#ifndef MPL11_WHILE_HPP
#define MPL11_WHILE_HPP

#include <mpl11/apply.hpp>
#include <mpl11/eval_if.hpp>
#include <mpl11/identity.hpp>

#include <cstddef>


namespace mpl11 {

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

} // end namespace mpl11

#endif // !MPL11_WHILE_HPP
