/**
 * This file defines unit tests for the pop_front metafunction.
 */

#include <mpl11/pop_front.hpp>
#include <mpl11/pack.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                pack<float, char, int>,
                pop_front<void, float, char, int>::type
              >::value, "");

static_assert(std::is_same<
                pack<>,
                pop_front<void>::type
              >::value, "");
