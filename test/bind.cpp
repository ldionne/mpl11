/**
 * This file defines unit tests for the bind metafunction.
 */

#include <mpl11/bind.hpp>

#include <mpl11/apply.hpp>
#include <mpl11/identity.hpp>
#include <mpl11/pack.hpp>
#include <mpl11/placeholders.hpp>
#include <mpl11/quote.hpp>
#include <mpl11/transform.hpp>

#include <type_traits>


using namespace mpl11;

using midentity = quote<identity>;

// Nested binds.
using delayed = bind<midentity, _1>;
using delayed_twice = bind<midentity, delayed>;
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
                apply<bind<_1, int>, midentity>::type,
                int
              >::value, "");

// bind as metafunction class to algorithm working on higher order functions.
static_assert(std::is_same<
                transform<bind<midentity, float>,
                    int, int, int
                >::type,
                pack<float, float, float>
              >::value, "");

// bind with many parameters.
using shuffled = bind<quote<pack>, _2, _1, _4, _3>;
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
    template <typename ...> struct apply;
};
template <> struct nullary::apply<> { using type = nullary; };
static_assert(std::is_same<
                apply<bind<nullary>>::type,
                nullary
              >::value, "");

// Equivalence between bind and bind_pack.
static_assert(std::is_same<
                bind<midentity, _1>,
                bind_pack<pack<midentity, _1>>
              >::value, "");

// bind with the special _all placeholder
static_assert(std::is_same<
                apply<bind<quote<pack>, _all>, int, char, pack<double>>::type,
                pack<int, char, pack<double>>
              >::value, "");

// bind with a placeholder inside the arguments (it should not be replaced)
static_assert(std::is_same<
                apply<bind<midentity, _1>, _1>::type,
                _1
              >::value, "");
