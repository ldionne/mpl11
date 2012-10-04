/**
 * This file defines unit tests for the empty metafunction.
 */

#include <mpl11/empty.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                empty<int>::type,
                std::false_type
              >::value, "");

static_assert(std::is_same<
                empty<int, float, char>::type,
                std::false_type
              >::value, "");

static_assert(std::is_same<
                empty<>::type,
                std::true_type
              >::value, "");
