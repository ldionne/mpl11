/**
 * This file defines unit tests for the apply metafunction.
 */

#include <mpl11/apply.hpp>
#include <mpl11/identity.hpp>
#include <mpl11/pack.hpp>
#include <mpl11/quote.hpp>

#include <type_traits>


using namespace mpl11;

struct take2nd {
    template <typename T, typename U>
    struct apply { using type = U; };
};

static_assert(std::is_same<
                int,
                apply<quote<identity>, int>::type
              >::value, "");

static_assert(std::is_same<
                float,
                apply_pack<take2nd, pack<char, float>>::type
              >::value, "");
