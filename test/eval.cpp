/**
 * This file defines unit tests for the eval metafunction.
 */

#include <duck/eval.hpp>

#include <type_traits>


#define ASSERT_SAME(x, y) static_assert(std::is_same<x, y>::value, "")

template <typename T>
struct delayed {
    using type = T;
};

ASSERT_SAME(duck::eval<delayed<int>>::type, int);
