/**
 * This file defines unit tests for the requires metafunction.
 */

#include <duck/requires.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::requires<std::true_type, int>::type,
                int
              >::value, "");

static_assert(std::is_same<
                duck::requires<std::true_type, std::true_type, int>::type,
                int
              >::value, "");


template <typename T> typename
    duck::requires<typename std::is_same<int, T>::type,
T>::type func() { return 0; }

template <typename T> typename
    duck::requires<
        typename std::is_same<
            typename std::is_same<int, T>::type,
            std::false_type
        >::type,
void>::type func() { }

static_assert(std::is_same<
                decltype(func<int>()),
                int
              >::value, "");

static_assert(std::is_same<
                decltype(func<float>()),
                void
              >::value, "");

static_assert(std::is_same<
                decltype(func<char>()),
                void
              >::value, "");
