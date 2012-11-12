/**
 * This file defines unit tests for the `apply` metafunction.
 */

#include <mpl11/apply.hpp>
#include <mpl11/identity.hpp>
#include <mpl11/quote.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                int,
                apply<quote<identity>, int>::type
              >::value, "");
