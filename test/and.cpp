/**
 * This file defines unit tests for the and metafunction.
 */

#include <duck/and.hpp>

#include <type_traits>


using true_ = std::true_type;
using false_ = std::false_type;

static_assert(duck::and_<true_, true_>::value, "");
static_assert(!duck::and_<true_, false_>::value, "");
static_assert(!duck::and_<false_, true_>::value, "");
static_assert(!duck::and_<false_, false_>::value, "");

static_assert(!duck::and_<true_, true_, false_>::value, "");
static_assert(duck::and_<true_, true_, true_>::value, "");

// Make sure ::type is alright, not only ::value.
static_assert(std::is_same<
                duck::and_<true_, true_>::type,
                std::true_type
              >::value, "");

static_assert(std::is_same<
                duck::and_<false_, true_>::type,
                std::false_type
              >::value, "");

// Make sure metafunctions are evaluated.
struct mtrue_ { using type = std::true_type; };
struct mfalse_ { using type = std::false_type; };
static_assert(std::is_same<
                duck::and_<mtrue_, mtrue_, mtrue_>::type,
                std::true_type
              >::value, "");

static_assert(std::is_same<
                duck::and_<mtrue_, mfalse_>::type,
                std::false_type
              >::value, "");
