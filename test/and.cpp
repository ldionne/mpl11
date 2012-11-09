/**
 * This file defines unit tests for the and metafunction.
 */

#include <mpl11/and.hpp>
#include <mpl11/bool.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(and_<true_, true_>::value, "");
static_assert(!and_<true_, false_>::value, "");
static_assert(!and_<false_, true_>::value, "");
static_assert(!and_<false_, false_>::value, "");

static_assert(!and_<true_, true_, false_>::value, "");
static_assert(and_<true_, true_, true_>::value, "");

// Make sure ::type is alright, not only ::value.
static_assert(std::is_same<
                and_<true_, true_>::type,
                true_
              >::value, "");

static_assert(std::is_same<
                and_<false_, true_>::type,
                false_
              >::value, "");

// Make sure metafunctions are evaluated.
struct mtrue_ { using type = true_; };
struct mfalse_ { using type = false_; };
static_assert(std::is_same<
                and_<mtrue_, mtrue_, mtrue_>::type,
                true_
              >::value, "");

static_assert(std::is_same<
                and_<mtrue_, mfalse_>::type,
                false_
              >::value, "");
