/**
 * This file defines unit tests for the quote metafunction.
 */

#include <mpl11/quote.hpp>
#include <mpl11/apply.hpp>

#include <type_traits>


using namespace mpl11;

template <typename T> struct T_ { using type = T; };

static_assert(std::is_same<
                apply<quote<T_>, int>::type,
                T_<int>::type
              >::value, "");
