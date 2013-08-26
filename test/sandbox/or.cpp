/*!
 * @file
 * This file contains unit tests for `boost::mpl11::or_`.
 */

#include <boost/mpl11/or.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/identity.hpp>


using namespace boost::mpl11;

static_assert(or_<true_, true_>::value, "");
static_assert(or_<true_, false_>::value, "");
static_assert(or_<false_, true_>::value, "");
static_assert(!or_<false_, false_>::value, "");

static_assert(or_<true_, true_, false_>::value, "");
static_assert(!or_<false_, false_, false_>::value, "");

// Make sure ::type is alright, not only ::value.
static_assert(or_<true_, false_>::type::value, "");

static_assert(!or_<false_, false_>::type::value, "");

// Make sure metafunctions are evaluated.
static_assert(!or_<identity<false_>, identity<false_>, identity<false_>>::value, "");
static_assert(or_<identity<false_>, identity<true_>>::value, "");


int main() { }
