/**
 * This file defines unit tests for the and metafunction.
 */

#include <duck/and.hpp>

#include <type_traits>


using duck::and_;

static_assert(and_<std::true_type, std::true_type>::value, "");
static_assert(!and_<std::true_type, std::false_type>::value, "");
static_assert(!and_<std::false_type, std::true_type>::value, "");
static_assert(!and_<std::false_type, std::false_type>::value, "");

static_assert(and_<>::value, "");
static_assert(and_<std::true_type>::value, "");
static_assert(!and_<std::false_type>::value, "");
static_assert(!and_<std::true_type, std::true_type, std::false_type>::value, "");
static_assert(and_<std::true_type, std::true_type, std::true_type>::value, "");
