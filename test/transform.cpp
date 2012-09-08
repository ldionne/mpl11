/**
 * This file defines unit tests for the transform metafunction.
 */

#include <duck/transform.hpp>

#include <duck/pack.hpp>

#include <type_traits>


struct add2 {
    template <typename IntegralConstant>
    struct apply
        : std::integral_constant<int, IntegralConstant::value + 2> { };
};

static_assert(std::is_same<
                duck::transform<add2,
                    std::integral_constant<int, 0>,
                    std::integral_constant<int, 1>,
                    std::integral_constant<int, 2>,
                    std::integral_constant<int, 3>
                >::type,
                duck::pack<
                    std::integral_constant<int, 2>,
                    std::integral_constant<int, 3>,
                    std::integral_constant<int, 4>,
                    std::integral_constant<int, 5>
                >
              >::value, "");
