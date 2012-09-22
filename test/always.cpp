/**
 * This file defines unit tests for the always metafunction class.
 */

#include <duck/always.hpp>
#include <duck/all_of.hpp>
#include <duck/apply.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::apply<duck::always<int>, char, float, double>::type,
                int
              >::value, "");

static_assert(std::is_same<
                duck::apply<duck::always<int>>::type,
                int
              >::value, "");

// Test interoperation with an algorithm.
static_assert(std::is_same<
                duck::all_of<duck::always<std::true_type>,
                    std::false_type,
                    std::false_type,
                    std::false_type
                >::type,
                std::true_type
              >::value, "");
