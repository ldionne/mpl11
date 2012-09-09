/**
 * This file defines unit tests for the size metafunction.
 */

#include <duck/size.hpp>


static_assert(duck::size<>::value == 0, "");
static_assert(duck::size<int>::value == 1, "");
static_assert(duck::size<float, char, void>::value == 3, "");
