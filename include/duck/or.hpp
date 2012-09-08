/**
 * This file defines the or_ metafunction.
 */

#ifndef DUCK_OR_HPP
#define DUCK_OR_HPP

#include <duck/accumulate.hpp>
#include <duck/bool.hpp>
#include <duck/quote.hpp>


namespace duck {

/**
 * Compute the logical or of its arguments.
 */
namespace detail {
    template <typename T, typename U>
    struct or_impl : bool_<T::value || U::value> { };
}

template <typename ...> struct or_;
template <> struct or_<> : true_ { };

template <typename T, typename ...Rest>
struct or_<T, Rest...>
    : accumulate<quote<detail::or_impl>, false_, T, Rest...>::type { };


namespace test {

static_assert(or_<true_, true_>::value, "");
static_assert(or_<true_, false_>::value, "");
static_assert(or_<false_, true_>::value, "");
static_assert(!or_<false_, false_>::value, "");

static_assert(or_<>::value, "");
static_assert(or_<true_>::value, "");
static_assert(!or_<false_>::value, "");
static_assert(or_<true_, true_, false_>::value, "");
static_assert(!or_<false_, false_, false_>::value, "");
static_assert(or_<true_, false_, true_, true_>::value, "");

} // end namespace test

} // end namespace duck

#endif // !DUCK_OR_HPP
