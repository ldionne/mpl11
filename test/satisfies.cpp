/**
 * This file defines unit tests for the satisfies metafunction.
 */

#include <mpl11/satisfies.hpp>

#include <type_traits>


using namespace mpl11;

struct Satisfied {
    template <typename T>
    struct apply { using type = std::true_type; };
};

struct Unsatisfied {
    template <typename T>
    struct apply { using type = std::false_type; };
};

template <typename T>
struct same_as {
    template <typename U>
    struct apply : std::is_same<T, U> { };
};

static_assert(std::is_same<
                satisfies<Satisfied, int>::type,
                std::true_type
              >::value, "");

static_assert(std::is_same<
                satisfies<Satisfied, Satisfied, int>::type,
                std::true_type
              >::value, "");

static_assert(std::is_same<
                satisfies<Unsatisfied, int>::type,
                std::false_type
              >::value, "");

static_assert(std::is_same<
                satisfies<Unsatisfied, Unsatisfied, int>::type,
                std::false_type
              >::value, "");

static_assert(std::is_same<
                satisfies<Satisfied, Unsatisfied, int>::type,
                std::false_type
              >::value, "");

static_assert(std::is_same<
                satisfies<same_as<int>, int>::type,
                std::true_type
              >::value, "");

static_assert(std::is_same<
                satisfies<same_as<int>, float>::type,
                std::false_type
              >::value, "");
