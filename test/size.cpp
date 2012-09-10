/**
 * This file defines unit tests for the size metafunction.
 */

#include <duck/size.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::size<>::type,
                std::integral_constant<std::size_t, 0>
              >::value, "");

static_assert(std::is_same<
                duck::size<int>::type,
                std::integral_constant<std::size_t, 1>
              >::value, "");

static_assert(std::is_same<
                duck::size<float, char, void>::type,
                std::integral_constant<std::size_t, 3>
              >::value, "");
