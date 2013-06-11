/*!
 * @file
 * This file contains unit tests for `boost::mpl11::and_`.
 */

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/identity.hpp>

#include <type_traits>


using namespace boost::mpl11;

static_assert(and_<true_, true_>::value, "");
static_assert(!and_<true_, false_>::value, "");
static_assert(!and_<false_, true_>::value, "");
static_assert(!and_<false_, false_>::value, "");

static_assert(!and_<true_, true_, false_>::value, "");
static_assert(and_<true_, true_, true_>::value, "");

// Make sure ::type is alright, not only ::value.
static_assert(std::is_same<
    and_<true_, true_>::type,
    true_
>::value, "");

static_assert(std::is_same<
    and_<false_, true_>::type,
    false_
>::value, "");

// Make sure metafunctions are evaluated.
static_assert(std::is_same<
    and_<identity<true_>, identity<true_>, identity<true_>>::type,
    true_
>::value, "");

static_assert(std::is_same<
    and_<identity<true_>, identity<false_>>::type,
    false_
>::value, "");
