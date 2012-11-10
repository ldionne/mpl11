/**
 * This file defines placeholders for bind and lambda expressions.
 */

#ifndef MPL11_PLACEHOLDERS_HPP
#define MPL11_PLACEHOLDERS_HPP

#include <mpl11/any_of.hpp>
#include <mpl11/quote.hpp>
#include <mpl11/types.hpp>

#include <cstddef>


namespace mpl11 {

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
struct _all { };

/**
 * Determine whether an expression is a placeholder expression.
 */
template <typename T>
struct is_placeholder_expr : false_ { };

template <std::size_t i>
struct is_placeholder_expr<placeholder<i>> : true_ { };

template <>
struct is_placeholder_expr<_all> : true_ { };

template <template <typename ...> class F, typename ...Placeholders>
struct is_placeholder_expr<F<Placeholders...>>
    : any_of<
        quote<is_placeholder_expr>,
        Placeholders...
    >
{ };

} // end namespace mpl11

#endif // !MPL11_PLACEHOLDERS_HPP
