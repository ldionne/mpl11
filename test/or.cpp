/**
 * This file defines unit tests for the or metafunction.
 */

#include <mpl11/or.hpp>

#include <type_traits>


using namespace mpl11;

using true_ = std::true_type;
using false_ = std::false_type;

static_assert(or_<true_, true_>::value, "");
static_assert(or_<true_, false_>::value, "");
static_assert(or_<false_, true_>::value, "");
static_assert(!or_<false_, false_>::value, "");

static_assert(or_<true_, true_, false_>::value, "");
static_assert(!or_<false_, false_, false_>::value, "");

// Make sure ::type is alright, not only ::value.
static_assert(std::is_same<
                or_<true_, false_>::type,
                std::true_type
              >::value, "");

static_assert(std::is_same<
                or_<false_, false_>::type,
                std::false_type
              >::value, "");

// Make sure metafunctions are evaluated.
struct mtrue_ { using type = std::true_type; };
struct mfalse_ { using type = std::false_type; };
static_assert(std::is_same<
                or_<mfalse_, mfalse_, mfalse_>::type,
                std::false_type
              >::value, "");

static_assert(std::is_same<
                or_<mtrue_, mfalse_>::type,
                std::true_type
              >::value, "");
