/**
 * This file defines unit tests for the at metafunction.
 */

#include <duck/at.hpp>

#include <type_traits>


static_assert(std::is_same<
                int,
                duck::at<2, void, void, int, void>::type
              >::value, "");

static_assert(std::is_same<
                int,
                duck::at<0, int, void, void, void>::type
              >::value, "");

static_assert(std::is_same<
                int,
                duck::at<3, void, void, void, int>::type
              >::value, "");
