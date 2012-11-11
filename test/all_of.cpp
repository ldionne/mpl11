/**
 * This file defines unit tests for the all_of metafunction.
 */

#include <mpl11/all_of.hpp>
#include <mpl11/always.hpp>
#include <mpl11/identity.hpp>
#include <mpl11/quote.hpp>
#include <mpl11/types.hpp>


using namespace mpl11;

static_assert(all_of<always<true_>>::value, "");
static_assert(all_of<always<false_>>::value, "");

static_assert(all_of<always<true_>, int>::value, "");
static_assert(all_of<always<true_>, int, float, char>::value, "");

static_assert(!all_of<always<false_>, int>::value, "");
static_assert(!all_of<always<false_>, int, float, char>::value, "");

static_assert(all_of<quote<identity>, true_, true_>::value, "");
static_assert(!all_of<quote<identity>, true_, false_>::value, "");
