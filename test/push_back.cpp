/**
 * This file defines unit tests for the push_back metafunction.
 */

#include <duck/push_back.hpp>

#include <duck/pack.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::pack<float, char, int, void>,
                duck::push_back<void, duck::pack<float, char, int>>::type
              >::value, "");

static_assert(std::is_same<
                duck::pack<void>,
                duck::push_back<void, duck::pack<>>::type
              >::value, "");
