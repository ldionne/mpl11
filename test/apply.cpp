/**
 * This file defines unit tests for the apply metafunction.
 */

#include <duck/apply.hpp>
#include <duck/pack.hpp>

#include <type_traits>


struct identity {
    template <typename T>
    struct apply { using type = T; };
};

static_assert(std::is_same<
                int,
                duck::apply<identity, int>::type
              >::value, "");


struct take2nd {
    template <typename T, typename U>
    struct apply { using type = U; };
};

static_assert(std::is_same<
                float,
                duck::apply_pack<take2nd, duck::pack<char, float>>::type
              >::value, "");
