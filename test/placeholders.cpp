/**
 * This file defines unit tests for the placeholders.
 */

#include <duck/placeholders.hpp>


template <typename ...T>
struct my_pack { using type = my_pack<T...>; };

static_assert(duck::is_placeholder_expr<
                duck::_1
              >::value, "");

static_assert(duck::is_placeholder_expr<
                my_pack<duck::_1, duck::_2>
              >::value, "");

static_assert(duck::is_placeholder_expr<
                my_pack<duck::_1, my_pack<int, duck::_2>>
              >::value, "");

static_assert(duck::is_placeholder_expr<
                my_pack<int, my_pack<float, my_pack<duck::_3>>>
              >::value, "");

static_assert(!duck::is_placeholder_expr<
                int
              >::value, "");

static_assert(!duck::is_placeholder_expr<
                my_pack<int, float, char>
              >::value, "");
