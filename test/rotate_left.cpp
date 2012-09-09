/**
 * This file defines unit tests for the rotate_left metafunction.
 */

#include <duck/rotate_left.hpp>

#include <duck/pack.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::pack<float, char, void, int>,
                duck::rotate_left<int, float, char, void>::type
              >::value, "");

static_assert(std::is_same<
                duck::pack<>,
                duck::rotate_left<>::type
              >::value, "");

static_assert(std::is_same<
                duck::pack<int>,
                duck::rotate_left<int>::type
              >::value, "");
