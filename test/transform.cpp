/**
 * This file defines unit tests for the transform metafunction.
 */

#include <mpl11/transform.hpp>
#include <mpl11/identity.hpp>
#include <mpl11/int.hpp>
#include <mpl11/pack.hpp>
#include <mpl11/quote.hpp>

#include <type_traits>


using namespace mpl11;

template <int i>
struct add {
    template <typename T>
    struct apply : int_<T::value + int_<i>::value> { };
};

static_assert(std::is_same<
                transform<add<2>,
                    int_<0>, int_<1>, int_<2>, int_<3>
                >::type,
                pack<
                    int_<2>, int_<3>, int_<4>, int_<5>
                >
              >::value, "");

static_assert(std::is_same<
                transform<quote<identity>, int, float, char>::type,
                pack<int, float, char>
              >::value, "");
