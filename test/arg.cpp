/**
 * This file defines unit tests for the arg metafunction class.
 */

#include <duck/arg.hpp>
#include <duck/apply.hpp>

#include <cstddef>
#include <type_traits>


template <std::size_t n, typename ...Args>
using keep = typename duck::apply<duck::arg<n>, Args...>::type;

static_assert(std::is_same<keep<1, int, float, char>, int>::value, "");
static_assert(std::is_same<keep<3, int, float, char>, char>::value, "");
