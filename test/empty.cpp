/**
 * This file defines unit tests for the empty metafunction.
 */

#include <duck/empty.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::empty<int>::type,
                std::false_type
              >::value, "");

static_assert(std::is_same<
                duck::empty<int, float, char>::type,
                std::false_type
              >::value, "");

static_assert(std::is_same<
                duck::empty<>::type,
                std::true_type
              >::value, "");
