/**
 * This file defines unit tests for the if metafunction.
 */

#include <mpl11/if.hpp>
#include <mpl11/types.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                if_<true_, float, char>::type,
                float
              >::value, "");

static_assert(std::is_same<
                if_<false_, float, char>::type,
                char
              >::value, "");
