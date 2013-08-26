/*!
 * @file
 * This file contains unit tests for `boost::mpl11::not_`.
 */

#include <boost/mpl11/not.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/identity.hpp>


using namespace boost::mpl11;

static_assert(!not_<true_>::value, "");
static_assert(not_<false_>::value, "");

static_assert(not_<false_>::type::value, "");
static_assert(!not_<true_>::type::value, "");

static_assert(not_<identity<false_>>::value, "");
static_assert(!not_<identity<true_>>::value, "");


int main() { }
