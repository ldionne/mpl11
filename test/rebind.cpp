/**
 * This file defines unit tests for the rebind metafunction.
 */

#include <mpl11/rebind.hpp>

#include <type_traits>


using namespace mpl11;

template <typename ...T> struct A { };
template <typename ...T> struct B { };

static_assert(std::is_same<
                rebind<A<int, float, char>, B>::type,
                B<int, float, char>
              >::value, "");

static_assert(std::is_same<rebind<A<>, B>::type, B<>>::value, "");
static_assert(std::is_same<rebind<A<>, A>::type, A<>>::value, "");
