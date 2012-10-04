/**
 * This file defines unit tests for the all_of metafunction.
 */

#include <mpl11/all_of.hpp>

#include <type_traits>


using namespace mpl11;

struct always_true {
    template <typename ...> struct apply : std::true_type { };
};

struct always_false {
    template <typename ...> struct apply : std::false_type { };
};

struct identity {
    template <typename T> struct apply { using type = T; };
};

static_assert(all_of<always_true>::value, "");
static_assert(all_of<always_false>::value, "");

static_assert(all_of<always_true, int>::value, "");
static_assert(all_of<always_true, int, float, char>::value, "");

static_assert(!all_of<always_false, int>::value, "");
static_assert(!all_of<always_false, int, float, char>::value, "");

static_assert(all_of<identity, std::true_type, std::true_type>::value, "");
static_assert(!all_of<identity, std::true_type, std::false_type>::value, "");
