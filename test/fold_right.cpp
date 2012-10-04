/**
 * This file defines unit tests for the @em fold_right metafunction.
 */

#include <mpl11/fold_right.hpp>
#include <mpl11/pack.hpp>
#include <mpl11/push_front.hpp>

#include <type_traits>


using namespace mpl11;

template <typename T>
struct add {
    template <typename X, typename Y>
    struct apply : std::integral_constant<T, X::value + Y::value> { };
};

static_assert(std::is_same<
                fold_right<add<int>, std::integral_constant<int, 0>,
                    std::integral_constant<int, 1>,
                    std::integral_constant<int, 2>,
                    std::integral_constant<int, 3>,
                    std::integral_constant<int, 4>
                >::type,
                std::integral_constant<int, 10>
              >::value, "");


struct accumulate_right {
    template <typename Head, typename TailPack>
    struct apply : push_front<Head, TailPack> { };
};

// Make sure the fold is made in the right direction.
static_assert(std::is_same<
                fold_right<accumulate_right,
                    pack<double>, int, float, char, void
                >::type,
                pack<int, float, char, void, double>
              >::value, "");

// Check with few arguments.
static_assert(std::is_same<
                fold_right<accumulate_right,
                    pack<double>, int
                >::type,
                pack<int, double>
              >::value, "");
