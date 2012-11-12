/**
 * This file defines placeholders for bind and lambda expressions.
 */

#ifndef MPL11_PLACEHOLDERS_HPP
#define MPL11_PLACEHOLDERS_HPP

#include <mpl11/arg.hpp>
#include <mpl11/bool.hpp>
#include <mpl11/or.hpp>

#include <cstddef>


namespace mpl11 {

template <std::size_t n> using placeholder = arg<n>;

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
 * Metafunction determining whether an expression is a placeholder expression.
 */
template <typename T>
struct is_placeholder_expr : false_ { };

template <std::size_t i>
struct is_placeholder_expr<placeholder<i>> : true_ { };

template <>
struct is_placeholder_expr<_all> : true_ { };

namespace detail {
    template <typename ...> struct any_is_placeholder_expr : false_ { };

    // Note: We can't use any_of because it uses apply, which
    //       causes a circular dependency.
    template <typename First, typename ...Rest>
    struct any_is_placeholder_expr<First, Rest...>
        : or_<
            is_placeholder_expr<First>,
            any_is_placeholder_expr<Rest...>
        >
    { };
} // end namespace detail

template <template <typename ...> class F, typename ...Placeholders>
struct is_placeholder_expr<F<Placeholders...>>
    : detail::any_is_placeholder_expr<Placeholders...>
{ };

} // end namespace mpl11

#endif // !MPL11_PLACEHOLDERS_HPP
