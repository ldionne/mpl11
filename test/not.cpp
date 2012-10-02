/**
 * This file defines unit tests for the not_ metafunction.
 */

#include <duck/not.hpp>

#include <type_traits>


static_assert(std::is_same<
                duck::not_<std::true_type>::type,
                std::false_type
              >::value, "");

static_assert(std::is_same<
                duck::not_<std::false_type>::type,
                std::true_type
              >::value, "");

static_assert(duck::not_<std::false_type>::value, "");
static_assert(!duck::not_<std::true_type>::value, "");

struct mtrue_ { using type = std::true_type; };
struct mfalse_ { using type = std::false_type; };
static_assert(duck::not_<mfalse_>::value, "");
static_assert(!duck::not_<mtrue_>::value, "");
