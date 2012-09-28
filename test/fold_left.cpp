/**
 * This file defines unit tests for the @em fold_left metafunction.
 */

#include <duck/fold_left.hpp>
#include <duck/pack.hpp>
#include <duck/push_back.hpp>

#include <type_traits>


template <typename T>
struct add {
    template <typename X, typename Y>
    struct apply : std::integral_constant<T, X::value + Y::value> { };
};

static_assert(std::is_same<
                duck::fold_left<add<int>, std::integral_constant<int, 0>,
                    std::integral_constant<int, 1>,
                    std::integral_constant<int, 2>,
                    std::integral_constant<int, 3>,
                    std::integral_constant<int, 4>
                >::type,
                std::integral_constant<int, 10>
              >::value, "");


struct accumulate_left {
    template <typename HeadPack, typename Tail>
    struct apply : duck::push_back<Tail, HeadPack> { };
};

// Make sure the fold is made in the right direction.
static_assert(std::is_same<
                duck::fold_left<accumulate_left,
                    duck::pack<double>, int, float, char, void
                >::type,
                duck::pack<double, int, float, char, void>
              >::value, "");

// Check with few arguments.
static_assert(std::is_same<
                duck::fold_left<accumulate_left,
                    duck::pack<double>, int
                >::type,
                duck::pack<double, int>
              >::value, "");
