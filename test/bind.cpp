/**
 * This file defines unit tests for the bind metafunction.
 */

#include <mpl11/bind.hpp>

#include <mpl11/apply.hpp>
#include <mpl11/pack.hpp>
#include <mpl11/placeholders.hpp>
#include <mpl11/transform.hpp>

#include <type_traits>


using namespace mpl11;

struct identity {
    template <typename T> struct apply { using type = T; };
};


// Nested binds.
using delayed = bind<identity, _1>;
using delayed_twice = bind<identity, delayed>;
static_assert(std::is_same<
                apply<delayed, int>::type,
                int
              >::value, "");

static_assert(std::is_same<
                apply<delayed_twice, int>::type,
                int
              >::value, "");

// Simple bind with an identity metafunction.
static_assert(std::is_same<
                apply<bind<_1, int>, identity>::type,
                int
              >::value, "");

// bind as metafunction class to algorithm working on higher order functions.
static_assert(std::is_same<
                transform<bind<identity, float>,
                    int, int, int
                >::type,
                pack<float, float, float>
              >::value, "");


// bind with many parameters.
struct mpack {
    template <typename ...T>
    struct apply { using type = pack<T...>; };
};
using shuffled = bind<mpack, _2, _1, _4, _3>;
static_assert(std::is_same<
                shuffled::apply<int, float, char, void>::type,
                pack<float, int, void, char>
              >::value, "");

// bind with too many parameters.
static_assert(std::is_same<
                shuffled::apply<int, float, char, void, short, double>::type,
                pack<float, int, void, char>
              >::value, "");

// bind without arguments.
struct self {
    template <typename ...> struct apply { using type = self; };
};
static_assert(std::is_same<
                self,
                apply<bind<self>>::type
              >::value, "");

// bind with nullary template.
struct nullary {
    template <typename ...> struct apply { using type = int; };
};
template <> struct nullary::apply<> { using type = nullary; };
static_assert(std::is_same<
                apply<bind<nullary>>::type,
                nullary
              >::value, "");

// Equivalence between bind and bind_pack.
static_assert(std::is_same<
                bind<identity, _1>,
                bind_pack<pack<identity, _1>>
              >::value, "");
