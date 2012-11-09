/**
 * This file defines unit tests for the cast metafunction.
 */

#include <mpl11/cast.hpp>
#include <mpl11/types.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<cast<bool, int_<2>>::type, true_>::value, "");
static_assert(std::is_same<cast<bool, int_<0>>::type, false_>::value, "");
