/**
 * This file defines unit tests for the any_of metafunction.
 */

#include <mpl11/any_of.hpp>
#include <mpl11/always.hpp>
#include <mpl11/bool.hpp>
#include <mpl11/identity.hpp>
#include <mpl11/quote.hpp>


using namespace mpl11;

static_assert(!any_of<always<true_>>::value, "");
static_assert(!any_of<always<false_>>::value, "");

static_assert(any_of<always<true_>, int>::value, "");
static_assert(any_of<always<true_>, int, float, char>::value, "");

static_assert(!any_of<always<false_>, int>::value, "");
static_assert(!any_of<always<false_>, int, float, char>::value, "");

static_assert(any_of<quote<identity>, true_, false_>::value, "");
static_assert(!any_of<quote<identity>, false_, false_>::value, "");
