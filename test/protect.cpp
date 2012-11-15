/**
 * This file defines unit tests for the `protect` metafunction.
 */

#include <mpl11/protect.hpp>
#include <mpl11/apply.hpp>
#include <mpl11/bind.hpp>
#include <mpl11/bool.hpp>
#include <mpl11/if.hpp>
#include <mpl11/placeholders.hpp>
#include <mpl11/protect.hpp>
#include <mpl11/quote.hpp>

#include <type_traits>


using namespace mpl11;

struct take2nd {
    template <typename T1, typename T2>
    struct apply { using type = T2; };
};

using bind_take2nd = bind<take2nd, _1, _2>;

typedef bind<quote<if_>, _1, _2, bind_take2nd> b1;
typedef bind<quote<if_>, _1, _2, protect<bind_take2nd>> b2;

typedef apply<b1, false_, char>::type r1;
typedef apply<b2, false_, char>::type r2;

static_assert(std::is_same<r1, char>::value, "");
static_assert(std::is_same<r2, protect<bind_take2nd>>::value, "");
