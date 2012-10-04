/**
 * This file defines unit tests for the back metafunction.
 */

#include <mpl11/back.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                int,
                back<float, char, int>::type
              >::value, "");

static_assert(std::is_same<
                int,
                back<int>::type
              >::value, "");
