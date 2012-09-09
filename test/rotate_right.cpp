/**
 * This file defines unit tests for the rotate_right metafunction.
 */

#include <duck/rotate_right.hpp>

#include <duck/pack.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::pack<void, int, float, char>,
                duck::rotate_right<int, float, char, void>::type
              >::value, "");

static_assert(std::is_same<
                duck::pack<>,
                duck::rotate_right<>::type
              >::value, "");

static_assert(std::is_same<
                duck::pack<int>,
                duck::rotate_right<int>::type
              >::value, "");
