/**
 * This file defines unit tests for the size metafunction.
 */

#include <mpl11/size.hpp>
#include <mpl11/size_t.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                size<>::type, mpl11::size_t<0>
              >::value, "");

static_assert(std::is_same<
                size<int>::type, mpl11::size_t<1>
              >::value, "");

static_assert(std::is_same<
                size<float, char, void>::type, mpl11::size_t<3>
              >::value, "");

static_assert(size<float, char, void>::value == 3, "");
