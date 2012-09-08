/**
 * This file defines unit tests for the bind metafunction.
 */

#include <duck/bind.hpp>

#include <duck/apply.hpp>
#include <duck/pack.hpp>
#include <duck/placeholders.hpp>
#include <duck/transform.hpp>

#include <type_traits>


struct identity {
    template <typename T> struct apply { using type = T; };
};


// Nested binds.
using delayed = duck::bind<identity, duck::_1>;
using delayed_twice = duck::bind<identity, delayed>;
static_assert(std::is_same<
                duck::apply<delayed, int>::type,
                int
              >::value, "");

static_assert(std::is_same<
                duck::apply<delayed_twice, int>::type,
                int
              >::value, "");

// Simple bind with an identity metafunction.
static_assert(std::is_same<
                duck::apply<duck::bind<duck::_1, int>, identity>::type,
                int
              >::value, "");

// bind as metafunction class to algorithm working on higher order functions.
static_assert(std::is_same<
                duck::transform<duck::bind<identity, float>,
                    int, int, int
                >::type,
                duck::pack<float, float, float>
              >::value, "");


// bind with many parameters.
struct mpack {
    template <typename ...T>
    struct apply { using type = duck::pack<T...>; };
};
using shuffled = duck::bind<mpack, duck::_2, duck::_1, duck::_4, duck::_3>;
static_assert(std::is_same<
                shuffled::apply<int, float, char, void>::type,
                duck::pack<float, int, void, char>
              >::value, "");

// bind with too many parameters.
static_assert(std::is_same<
                shuffled::apply<int, float, char, void, short, double>::type,
                duck::pack<float, int, void, char>
              >::value, "");

// bind without arguments.
struct self {
    template <typename ...> struct apply { using type = self; };
};
static_assert(std::is_same<
                self,
                duck::apply<duck::bind<self>>::type
              >::value, "");

// bind with nullary template.
struct nullary {
    template <typename ...> struct apply { using type = int; };
};
template <> struct nullary::apply<> { using type = nullary; };
static_assert(std::is_same<
                duck::apply<duck::bind<nullary>>::type,
                nullary
              >::value, "");

// Equivalence between bind and bind_pack.
static_assert(std::is_same<
                duck::bind<identity, duck::_1>,
                duck::bind_pack<duck::pack<identity, duck::_1>>
              >::value, "");
