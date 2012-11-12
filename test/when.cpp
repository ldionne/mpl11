/**
 * This file defines unit tests for the when metafunction.
 */

#include <mpl11/when.hpp>
#include <mpl11/bool.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<when<true_, float>::type, float>::value, "");
