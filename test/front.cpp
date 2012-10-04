/**
 * This file defines unit tests for the front metafunction.
 */

#include <mpl11/front.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                front<int, float, char>::type,
                int
              >::value, "");

static_assert(std::is_same<
                front<int>::type,
                int
              >::value, "");
