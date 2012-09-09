/**
 * This file defines unit tests for the if metafunction.
 */

#include <duck/if.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::if_<std::true_type, float, char>::type,
                float
              >::value, "");

static_assert(std::is_same<
                duck::if_<std::false_type, float, char>::type,
                char
              >::value, "");
