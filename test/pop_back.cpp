/**
 * This file defines unit tests for the pop_back metafunction.
 */

#include <duck/pop_back.hpp>

#include <duck/pack.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::pack<int, float, char>,
                duck::pop_back<int, float, char, void>::type
              >::value, "");

static_assert(std::is_same<
                duck::pack<>,
                duck::pop_back<void>::type
              >::value, "");
