/**
 * This file defines the and_ metafunction.
 */

#ifndef DUCK_AND_HPP
#define DUCK_AND_HPP

#include <duck/accumulate.hpp>
#include <duck/bool.hpp>
#include <duck/quote.hpp>


namespace duck {

/**
 * Compute the logical and of its arguments.
 */
namespace detail {
    template <typename T, typename U>
    struct and_impl : bool_<T::value && U::value> { };
}

template <typename ...> struct and_;
template <> struct and_<> : true_ { };

template <typename T, typename ...Rest>
struct and_<T, Rest...>
    : accumulate<quote<detail::and_impl>, true_, T, Rest...>::type { };


namespace test {

static_assert(and_<true_, true_>::value, "");
static_assert(!and_<true_, false_>::value, "");
static_assert(!and_<false_, true_>::value, "");
static_assert(!and_<false_, false_>::value, "");

static_assert(and_<>::value, "");
static_assert(and_<true_>::value, "");
static_assert(!and_<false_>::value, "");
static_assert(!and_<true_, true_, false_>::value, "");
static_assert(and_<true_, true_, true_>::value, "");
static_assert(!and_<true_, true_, false_, true_>::value, "");

} // end namespace test

} // end namespace duck

#endif // !DUCK_AND_HPP
