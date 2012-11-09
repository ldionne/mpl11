/**
 * This file defines unit tests for the satisfies metafunction.
 */

#include <mpl11/satisfies.hpp>
#include <mpl11/types.hpp>

#include <type_traits>


using namespace mpl11;

struct Satisfied {
    template <typename T>
    struct apply { using type = true_; };
};

struct Unsatisfied {
    template <typename T>
    struct apply { using type = false_; };
};

template <typename T>
struct same_as {
    template <typename U>
    struct apply : std::is_same<T, U> { };
};

static_assert(std::is_same<
                satisfies<Satisfied, int>::type,
                true_
              >::value, "");

static_assert(std::is_same<
                satisfies<Satisfied, Satisfied, int>::type,
                true_
              >::value, "");

static_assert(std::is_same<
                satisfies<Unsatisfied, int>::type,
                false_
              >::value, "");

static_assert(std::is_same<
                satisfies<Unsatisfied, Unsatisfied, int>::type,
                false_
              >::value, "");

static_assert(std::is_same<
                satisfies<Satisfied, Unsatisfied, int>::type,
                false_
              >::value, "");

static_assert(std::is_same<
                satisfies<same_as<int>, int>::type,
                true_
              >::value, "");

static_assert(std::is_same<
                satisfies<same_as<int>, float>::type,
                false_
              >::value, "");
