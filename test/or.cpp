/**
 * This file defines unit tests for the or metafunction.
 */

#include <duck/or.hpp>

#include <type_traits>


using true_ = std::true_type;
using false_ = std::false_type;

static_assert(duck::or_<true_, true_>::value, "");
static_assert(duck::or_<true_, false_>::value, "");
static_assert(duck::or_<false_, true_>::value, "");
static_assert(!duck::or_<false_, false_>::value, "");

static_assert(duck::or_<true_, true_, false_>::value, "");
static_assert(!duck::or_<false_, false_, false_>::value, "");

// Make sure ::type is alright, not only ::value.
static_assert(std::is_same<
                duck::or_<true_, false_>::type,
                std::true_type
              >::value, "");

static_assert(std::is_same<
                duck::or_<false_, false_>::type,
                std::false_type
              >::value, "");
