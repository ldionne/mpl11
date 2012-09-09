/**
 * This file defines unit tests for the satisfies metafunction.
 */

#include <duck/satisfies.hpp>

#include <type_traits>


struct Satisfied {
    template <typename T> struct apply : std::true_type { };
};

struct Unsatisfied {
    template <typename T> struct apply : std::false_type { };
};

static_assert(duck::satisfies<Satisfied, int>::value, "");
static_assert(duck::satisfies<Satisfied, Satisfied, int>::value, "");

static_assert(!duck::satisfies<Unsatisfied, int>::value, "");
static_assert(!duck::satisfies<Unsatisfied, Unsatisfied, int>::value, "");

static_assert(!duck::satisfies<Satisfied, Unsatisfied, int>::value, "");
