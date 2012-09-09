/**
 * This file defines unit tests for the empty metafunction.
 */

#include <duck/empty.hpp>


static_assert(!duck::empty<int>::value, "");
static_assert(!duck::empty<int, float, char>::value, "");
static_assert(duck::empty<>::value, "");
