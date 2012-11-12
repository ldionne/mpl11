/**
 * This file defines unit tests for the at metafunction.
 */

#include <mpl11/at.hpp>
#include <mpl11/size_t.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                int,
                at_c<2, void, void, int, void>::type
              >::value, "");

static_assert(std::is_same<
                int,
                at_c<0, int, void, void, void>::type
              >::value, "");

static_assert(std::is_same<
                int,
                at<mpl11::size_t<3>, void, void, void, int>::type
              >::value, "");
