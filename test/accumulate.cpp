/**
 * This file defines unit tests for the accumulate metafunction.
 */

#include <duck/accumulate.hpp>

#include <type_traits>


template <typename T>
struct add {
    template <typename X, typename Y>
    struct apply : std::integral_constant<T, X::value + Y::value> { };
};

static_assert(std::is_same<
                duck::accumulate<add<int>,
                    std::integral_constant<int, 1>,
                    std::integral_constant<int, 2>,
                    std::integral_constant<int, 3>,
                    std::integral_constant<int, 4>
                >::type,
                std::integral_constant<int, 10>
              >::value, "");
