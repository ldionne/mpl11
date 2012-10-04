/**
 * This file defines unit tests for the at metafunction.
 */

#include <mpl11/at.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                int,
                at<2, void, void, int, void>::type
              >::value, "");

static_assert(std::is_same<
                int,
                at<0, int, void, void, void>::type
              >::value, "");

static_assert(std::is_same<
                int,
                at<3, void, void, void, int>::type
              >::value, "");
