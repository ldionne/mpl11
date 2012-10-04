/**
 * This file defines unit tests for the rotate_left metafunction.
 */

#include <mpl11/rotate_left.hpp>
#include <mpl11/pack.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                pack<float, char, void, int>,
                rotate_left<int, float, char, void>::type
              >::value, "");

static_assert(std::is_same<
                pack<>,
                rotate_left<>::type
              >::value, "");

static_assert(std::is_same<
                pack<int>,
                rotate_left<int>::type
              >::value, "");
