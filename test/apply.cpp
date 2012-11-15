/**
 * This file defines unit tests for the `apply` metafunction.
 */

#include <mpl11/apply.hpp>
#include <mpl11/identity.hpp>
#include <mpl11/pack.hpp>
#include <mpl11/placeholders.hpp>
#include <mpl11/quote.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                int,
                apply<quote<identity>, int>::type
              >::value, "");

// apply with lambda expressions
static_assert(std::is_same<
                apply<identity<_1>, int>::type,
                int
              >::value, "");

static_assert(std::is_same<
                apply<pack<_1, _2, _all>, int, char, float>::type,
                pack<int, char, int, char, float>
              >::value, "");
