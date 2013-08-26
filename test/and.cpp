/*!
 * @file
 * This file contains unit tests for `boost::mpl11::and_`.
 */

#include <boost/mpl11/and.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/identity.hpp>


using namespace boost::mpl11;

static_assert(and_<true_, true_>::value, "");
static_assert(!and_<true_, false_>::value, "");
static_assert(!and_<false_, true_>::value, "");
static_assert(!and_<false_, false_>::value, "");

static_assert(!and_<true_, true_, false_>::value, "");
static_assert(and_<true_, true_, true_>::value, "");

// Make sure ::type is alright, not only ::value.
static_assert(and_<true_, true_>::type::value, "");
static_assert(!and_<false_, true_>::type::value, "");

// Make sure metafunctions are evaluated.
static_assert(and_<identity<true_>, identity<true_>>::value, "");
static_assert(!and_<identity<true_>, identity<false_>>::value, "");

// Make sure we short-circuit.
static_assert(!and_<false_, struct not_a_metafunction>::value, "");
static_assert(!and_<true_, false_, struct not_a_metafunction>::value, "");


int main() { }
