/**
 * This file defines placeholders for bind and lambda expressions.
 */

#ifndef DUCK_PLACEHOLDERS_HPP
#define DUCK_PLACEHOLDERS_HPP

#include <duck/apply.hpp>
#include <duck/or.hpp>
#include <duck/quote.hpp>
#include <duck/transform.hpp>

#include <cstddef>
#include <type_traits>


namespace duck {

template <std::size_t> struct placeholder { };

using _1 = placeholder<1>;
using _2 = placeholder<2>;
using _3 = placeholder<3>;
using _4 = placeholder<4>;
using _5 = placeholder<5>;
using _6 = placeholder<6>;
using _7 = placeholder<7>;
using _8 = placeholder<8>;
using _9 = placeholder<9>;

/**
 * Determine whether an expression is a placeholder expression.
 */
template <typename T>
struct is_placeholder_expr : std::false_type { };

template <std::size_t i>
struct is_placeholder_expr<placeholder<i>> : std::true_type { };

template <template <typename ...> class F, typename ...Placeholders>
struct is_placeholder_expr<F<Placeholders...>>
    : apply_pack<
        quote<or_>,
        typename transform<quote<is_placeholder_expr>, Placeholders...>::type
    >
{ };

} // end namespace duck

#endif // !DUCK_PLACEHOLDERS_HPP
