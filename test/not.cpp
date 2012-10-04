/**
 * This file defines unit tests for the not_ metafunction.
 */

#include <mpl11/not.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                not_<std::true_type>::type,
                std::false_type
              >::value, "");

static_assert(std::is_same<
                not_<std::false_type>::type,
                std::true_type
              >::value, "");

static_assert(not_<std::false_type>::value, "");
static_assert(!not_<std::true_type>::value, "");

struct mtrue_ { using type = std::true_type; };
struct mfalse_ { using type = std::false_type; };
static_assert(not_<mfalse_>::value, "");
static_assert(!not_<mtrue_>::value, "");
