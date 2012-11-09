/**
 * This file defines unit tests for the size metafunction.
 */

#include <mpl11/size.hpp>
#include <mpl11/types.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                size<>::type, size_t_<0>
              >::value, "");

static_assert(std::is_same<
                size<int>::type, size_t_<1>
              >::value, "");

static_assert(std::is_same<
                size<float, char, void>::type, size_t_<3>
              >::value, "");

static_assert(size<float, char, void>::value == 3, "");
