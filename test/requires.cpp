/**
 * This file defines unit tests for the requires metafunction.
 */

#include <mpl11/requires.hpp>
#include <mpl11/types.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                requires<true_, int>::type,
                int
              >::value, "");

static_assert(std::is_same<
                requires<true_, true_, int>::type,
                int
              >::value, "");


template <typename T> typename
    requires<typename std::is_same<int, T>::type,
T>::type func() { return 0; }

template <typename T> typename
    requires<
        typename std::is_same<
            typename std::is_same<int, T>::type,
            false_
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
