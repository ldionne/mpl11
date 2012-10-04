/**
 * This file defines unit tests for the pop_back metafunction.
 */

#include <mpl11/pop_back.hpp>
#include <mpl11/pack.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                pack<int, float, char>,
                pop_back<int, float, char, void>::type
              >::value, "");

static_assert(std::is_same<
                pack<>,
                pop_back<void>::type
              >::value, "");
