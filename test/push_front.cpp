/**
 * This file defines unit tests for the push_front metafunction.
 */

#include <duck/push_front.hpp>

#include <duck/pack.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::pack<void, float, char, int>,
                duck::push_front<void, duck::pack<float, char, int>>::type
              >::value, "");

static_assert(std::is_same<
                duck::pack<void>,
                duck::push_front<void, duck::pack<>>::type
              >::value, "");
