/**
 * This file defines unit tests for the transform metafunction.
 */

#include <duck/transform.hpp>

#include <duck/pack.hpp>

#include <type_traits>


template <int i>
using int_ = std::integral_constant<int, i>;

template <int i>
struct add {
    template <typename T>
    struct apply : int_<T::value + int_<i>::value> { };
};

static_assert(std::is_same<
                duck::transform<add<2>,
                    int_<0>, int_<1>, int_<2>, int_<3>
                >::type,
                duck::pack<
                    int_<2>, int_<3>, int_<4>, int_<5>
                >
              >::value, "");


struct identity {
    template <typename T>
    struct apply { using type = T; };
};
static_assert(std::is_same<
                duck::transform<identity,
                    int, float, char
                >::type,
                duck::pack<
                    int, float, char
                >
              >::value, "");
