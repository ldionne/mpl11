/**
 * This file defines unit tests for the push_front metafunction.
 */

#include <mpl11/push_front.hpp>
#include <mpl11/pack.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                pack<void, float, char, int>,
                push_front<void, pack<float, char, int>>::type
              >::value, "");

static_assert(std::is_same<
                pack<void>,
                push_front<void, pack<>>::type
              >::value, "");
