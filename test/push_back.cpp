/**
 * This file defines unit tests for the push_back metafunction.
 */

#include <mpl11/push_back.hpp>
#include <mpl11/pack.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                pack<float, char, int, void>,
                push_back<void, pack<float, char, int>>::type
              >::value, "");

static_assert(std::is_same<
                pack<void>,
                push_back<void, pack<>>::type
              >::value, "");
