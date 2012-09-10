/**
 * This file defines unit tests for the any_of metafunction.
 */

#include <duck/any_of.hpp>

#include <type_traits>


struct always_true {
    template <typename ...> struct apply : std::true_type { };
};

struct always_false {
    template <typename ...> struct apply : std::false_type { };
};

struct identity {
    template <typename T> struct apply { using type = T; };
};

static_assert(!duck::any_of<always_true>::value, "");
static_assert(!duck::any_of<always_false>::value, "");

static_assert(duck::any_of<always_true, int>::value, "");
static_assert(duck::any_of<always_true, int, float, char>::value, "");

static_assert(!duck::any_of<always_false, int>::value, "");
static_assert(!duck::any_of<always_false, int, float, char>::value, "");

static_assert(duck::any_of<identity, std::true_type, std::false_type>::value, "");
static_assert(!duck::any_of<identity, std::false_type, std::false_type>::value, "");
