/**
 * This file defines unit tests for the arg metafunction class.
 */

#include <mpl11/arg.hpp>
#include <mpl11/apply.hpp>

#include <cstddef>
#include <type_traits>


using namespace mpl11;

template <std::size_t n, typename ...Args>
using keep = typename apply<arg<n>, Args...>::type;

static_assert(std::is_same<keep<1, int, float, char>, int>::value, "");
static_assert(std::is_same<keep<3, int, float, char>, char>::value, "");
