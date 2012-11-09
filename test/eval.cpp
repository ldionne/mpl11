/**
 * This file defines unit tests for the eval metafunction.
 */

#include <mpl11/eval.hpp>

#include <type_traits>


using namespace mpl11;

template <typename T>
struct delayed {
    using type = T;
};

static_assert(std::is_same<eval<delayed<int>>::type, int>::value, "");
