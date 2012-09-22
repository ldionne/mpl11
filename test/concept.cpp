/**
 * This file defines unit tests for the concept metafunction.
 */

#include <duck/concept.hpp>
#include <duck/identity.hpp>

#include <type_traits>


using true_concept = duck::identity<std::true_type>;
using false_concept = duck::identity<std::false_type>;

static_assert(std::is_same<
                duck::concept<true_concept>::type,
                std::true_type
              >::value, "");

static_assert(std::is_same<
                duck::concept<true_concept, true_concept>::type,
                std::true_type
              >::value, "");

// Works with no concept.
static_assert(std::is_same<
                duck::concept<>::type,
                std::true_type
              >::value, "");

static_assert(std::is_same<
                duck::concept<false_concept>::type,
                std::false_type
              >::value, "");

static_assert(std::is_same<
                duck::concept<true_concept, false_concept>::type,
                std::false_type
              >::value, "");
