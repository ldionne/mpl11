/*!
 * @file
 * Contains unit tests for `boost::mpl11::or_`.
 */

#include <boost/mpl11/or.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/identity.hpp>


using boost::mpl11::or_;
using true_ = boost::mpl11::identity<boost::mpl11::true_>;
using false_ = boost::mpl11::identity<boost::mpl11::false_>;


static_assert(or_<true_, true_>::type::value, "");
static_assert(or_<true_, false_>::type::value, "");
static_assert(or_<false_, true_>::type::value, "");
static_assert(!or_<false_, false_>::type::value, "");

static_assert(or_<true_, true_, false_>::type::value, "");
static_assert(!or_<false_, false_, false_>::type::value, "");

// Make sure we short-circuit.
static_assert(or_<true_, struct not_a_metafunction>::type::value, "");
static_assert(or_<false_, true_, struct not_a_metafunction>::type::value, "");


int main() { }
