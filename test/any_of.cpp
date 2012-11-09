/**
 * This file defines unit tests for the any_of metafunction.
 */

#include <mpl11/any_of.hpp>
#include <mpl11/types.hpp>


using namespace mpl11;

struct always_true {
    template <typename ...> struct apply : true_ { };
};

struct always_false {
    template <typename ...> struct apply : false_ { };
};

struct identity {
    template <typename T> struct apply { using type = T; };
};

static_assert(!any_of<always_true>::value, "");
static_assert(!any_of<always_false>::value, "");

static_assert(any_of<always_true, int>::value, "");
static_assert(any_of<always_true, int, float, char>::value, "");

static_assert(!any_of<always_false, int>::value, "");
static_assert(!any_of<always_false, int, float, char>::value, "");

static_assert(any_of<identity, true_, false_>::value, "");
static_assert(!any_of<identity, false_, false_>::value, "");
