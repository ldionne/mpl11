/**
 * This file defines unit tests for the placeholders.
 */

#include <mpl11/placeholders.hpp>


using namespace mpl11;

template <typename ...T>
struct my_pack { using type = my_pack<T...>; };

static_assert(is_placeholder_expr<
                _1
              >::value, "");

static_assert(is_placeholder_expr<
                my_pack<_1, _2>
              >::value, "");

static_assert(is_placeholder_expr<
                my_pack<_1, my_pack<int, _2>>
              >::value, "");

static_assert(is_placeholder_expr<
                my_pack<int, my_pack<float, my_pack<_3>>>
              >::value, "");

static_assert(!is_placeholder_expr<
                int
              >::value, "");

static_assert(!is_placeholder_expr<
                my_pack<int, float, char>
              >::value, "");
