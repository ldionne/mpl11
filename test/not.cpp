/**
 * This file defines unit tests for the not_ metafunction.
 */

#include <mpl11/not.hpp>
#include <mpl11/bool.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<not_<true_>::type, false_>::value, "");
static_assert(std::is_same<not_<false_>::type, true_>::value, "");

static_assert(not_<false_>::value, "");
static_assert(!not_<true_>::value, "");

struct mtrue_ { using type = true_; };
struct mfalse_ { using type = false_; };
static_assert(not_<mfalse_>::value, "");
static_assert(!not_<mtrue_>::value, "");
