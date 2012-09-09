/**
 * This file defines unit tests for the quote metafunction.
 */

#include <duck/quote.hpp>

#include <duck/apply.hpp>

#include <type_traits>


template <typename T>
struct T_ { using type = T; };

static_assert(std::is_same<
                duck::apply<duck::quote<T_>, int>::type,
                T_<int>::type
              >::value, "");
