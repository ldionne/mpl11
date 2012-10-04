/**
 * This file defines unit tests for the when metafunction.
 */

#include <mpl11/when.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                when<std::true_type, float>::type,
                float
              >::value, "");
