/**
 * This file defines unit tests for the placeholders.
 */

#include <mpl11/placeholders.hpp>
#include <mpl11/pack.hpp>


using namespace mpl11;

static_assert(is_placeholder_expr<_1                            >::value, "");
static_assert(is_placeholder_expr<pack<_1, _2>                  >::value, "");
static_assert(is_placeholder_expr<_all                          >::value, "");
static_assert(is_placeholder_expr<pack<_1, pack<int, _2>>       >::value, "");
static_assert(is_placeholder_expr<pack<int, pack<float, pack<_3>>>
                                                                >::value, "");
static_assert(!is_placeholder_expr<int                          >::value, "");
static_assert(!is_placeholder_expr<pack<int, float, char>       >::value, "");
