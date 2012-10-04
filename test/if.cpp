/**
 * This file defines unit tests for the if metafunction.
 */

#include <mpl11/if.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                if_<std::true_type, float, char>::type,
                float
              >::value, "");

static_assert(std::is_same<
                if_<std::false_type, float, char>::type,
                char
              >::value, "");
