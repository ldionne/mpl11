/**
 * This file defines unit tests for the rotate_right metafunction.
 */

#include <mpl11/rotate_right.hpp>
#include <mpl11/pack.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                pack<void, int, float, char>,
                rotate_right<int, float, char, void>::type
              >::value, "");

static_assert(std::is_same<
                pack<>,
                rotate_right<>::type
              >::value, "");

static_assert(std::is_same<
                pack<int>,
                rotate_right<int>::type
              >::value, "");
