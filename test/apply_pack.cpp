/**
 * This file defines unit tests for the `apply_pack` metafunction.
 */

#include <mpl11/apply_pack.hpp>
#include <mpl11/pack.hpp>

#include <type_traits>


using namespace mpl11;

struct take2nd {
    template <typename T, typename U>
    struct apply { using type = U; };
};

static_assert(std::is_same<
                float,
                apply_pack<take2nd, pack<char, float>>::type
              >::value, "");
