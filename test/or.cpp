/**
 * This file defines unit tests for the or metafunction.
 */

#include <duck/or.hpp>

#include <type_traits>


using duck::or_;

static_assert(or_<std::true_type, std::true_type>::value, "");
static_assert(or_<std::true_type, std::false_type>::value, "");
static_assert(or_<std::false_type, std::true_type>::value, "");
static_assert(!or_<std::false_type, std::false_type>::value, "");

static_assert(or_<>::value, "");
static_assert(or_<std::true_type>::value, "");
static_assert(!or_<std::false_type>::value, "");
static_assert(or_<std::true_type, std::true_type, std::false_type>::value, "");
static_assert(!or_<std::false_type, std::false_type, std::false_type>::value, "");
