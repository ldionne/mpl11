/**
 * This file defines unit tests for the empty metafunction.
 */

#include <mpl11/empty.hpp>
#include <mpl11/types.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<empty<int>::type, false_>::value, "");
static_assert(std::is_same<empty<int, float, char>::type, false_>::value, "");
static_assert(std::is_same<empty<>::type, true_>::value, "");
