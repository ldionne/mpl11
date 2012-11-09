/**
 * This file defines unit tests for the or metafunction.
 */

#include <mpl11/or.hpp>
#include <mpl11/types.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(or_<true_, true_>::value, "");
static_assert(or_<true_, false_>::value, "");
static_assert(or_<false_, true_>::value, "");
static_assert(!or_<false_, false_>::value, "");

static_assert(or_<true_, true_, false_>::value, "");
static_assert(!or_<false_, false_, false_>::value, "");

// Make sure ::type is alright, not only ::value.
static_assert(std::is_same<
                or_<true_, false_>::type,
                true_
              >::value, "");

static_assert(std::is_same<
                or_<false_, false_>::type,
                false_
              >::value, "");

// Make sure metafunctions are evaluated.
struct mtrue_ { using type = true_; };
struct mfalse_ { using type = false_; };
static_assert(std::is_same<
                or_<mfalse_, mfalse_, mfalse_>::type,
                false_
              >::value, "");

static_assert(std::is_same<
                or_<mtrue_, mfalse_>::type,
                true_
              >::value, "");
