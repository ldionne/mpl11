/**
 * This file defines unit tests for the front metafunction.
 */

#include <duck/front.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::front<int, float, char>::type,
                int
              >::value, "");

static_assert(std::is_same<
                duck::front<int>::type,
                int
              >::value, "");
