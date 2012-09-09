/**
 * This file defines unit tests for the when metafunction.
 */

#include <duck/when.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::when<std::true_type, float>::type,
                float
              >::value, "");
