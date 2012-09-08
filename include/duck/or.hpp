/**
 * This file defines the or_ metafunction.
 */

#ifndef DUCK_OR_HPP
#define DUCK_OR_HPP

#include <duck/accumulate.hpp>
#include <duck/quote.hpp>

#include <type_traits>


namespace duck {

/**
 * Compute the logical or of its arguments.
 */
namespace detail {
    template <typename T, typename U>
    struct or_impl : std::integral_constant<bool, T::value || U::value> { };
}

template <typename ...> struct or_;
template <> struct or_<> : std::true_type { };

template <typename T, typename ...Rest>
struct or_<T, Rest...>
    : accumulate<
        quote<detail::or_impl>,
        std::false_type, T, Rest...
    >::type
{ };


namespace test {

static_assert(or_<std::true_type, std::true_type>::value, "");
static_assert(or_<std::true_type, std::false_type>::value, "");
static_assert(or_<std::false_type, std::true_type>::value, "");
static_assert(!or_<std::false_type, std::false_type>::value, "");

static_assert(or_<>::value, "");
static_assert(or_<std::true_type>::value, "");
static_assert(!or_<std::false_type>::value, "");
static_assert(or_<std::true_type, std::true_type, std::false_type>::value, "");
static_assert(!or_<std::false_type, std::false_type, std::false_type>::value, "");

} // end namespace test

} // end namespace duck

#endif // !DUCK_OR_HPP
