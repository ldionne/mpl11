/**
 * This file defines unit tests for the eval metafunction.
 */

#include <mpl11/eval.hpp>

#include <type_traits>


using namespace mpl11;

#define ASSERT_SAME(x, y) static_assert(std::is_same<x, y>::value, "")

template <typename T>
struct delayed {
    using type = T;
};

ASSERT_SAME(eval<delayed<int>>::type, int);
