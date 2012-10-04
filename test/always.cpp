/**
 * This file defines unit tests for the always metafunction class.
 */

#include <mpl11/always.hpp>
#include <mpl11/all_of.hpp>
#include <mpl11/apply.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                apply<always<int>, char, float, double>::type,
                int
              >::value, "");

static_assert(std::is_same<
                apply<always<int>>::type,
                int
              >::value, "");

// Test interoperation with an algorithm.
static_assert(std::is_same<
                all_of<always<std::true_type>,
                    std::false_type,
                    std::false_type,
                    std::false_type
                >::type,
                std::true_type
              >::value, "");
