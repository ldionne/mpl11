/**
 * This file defines unit tests for the back metafunction.
 */

#include <duck/back.hpp>

#include <type_traits>


static_assert(std::is_same<
                int,
                duck::back<float, char, int>::type
              >::value, "");

static_assert(std::is_same<
                int,
                duck::back<int>::type
              >::value, "");
