/**
 * This file defines unit tests for the @em fold_right metafunction.
 */

#include <duck/fold_right.hpp>
#include <duck/pack.hpp>
#include <duck/push_front.hpp>

#include <type_traits>


template <typename T>
struct add {
    template <typename X, typename Y>
    struct apply : std::integral_constant<T, X::value + Y::value> { };
};

static_assert(std::is_same<
                duck::fold_right<add<int>, std::integral_constant<int, 0>,
                    std::integral_constant<int, 1>,
                    std::integral_constant<int, 2>,
                    std::integral_constant<int, 3>,
                    std::integral_constant<int, 4>
                >::type,
                std::integral_constant<int, 10>
              >::value, "");


struct accumulate_right {
    template <typename Head, typename TailPack>
    struct apply : duck::push_front<Head, TailPack> { };
};

// Make sure the fold is made in the right direction.
static_assert(std::is_same<
                duck::fold_right<accumulate_right,
                    duck::pack<double>, int, float, char, void
                >::type,
                duck::pack<int, float, char, void, double>
              >::value, "");

// Check with few arguments.
static_assert(std::is_same<
                duck::fold_right<accumulate_right,
                    duck::pack<double>, int
                >::type,
                duck::pack<int, double>
              >::value, "");
