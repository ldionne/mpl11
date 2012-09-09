/**
 * This file defines unit tests for the pop_front metafunction.
 */

#include <duck/pop_front.hpp>

#include <duck/pack.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::pack<float, char, int>,
                duck::pop_front<void, float, char, int>::type
              >::value, "");

static_assert(std::is_same<
                duck::pack<>,
                duck::pop_front<void>::type
              >::value, "");
