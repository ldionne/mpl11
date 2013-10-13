/*!
 * @file
 * Contains unit tests for the default implementation of `boost::mpl11::and_`.
 */

#include <boost/mpl11/and.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/identity.hpp>


using boost::mpl11::and_;
using true_ = boost::mpl11::identity<boost::mpl11::true_>;
using false_ = boost::mpl11::identity<boost::mpl11::false_>;


static_assert(and_<true_, true_>::type::value, "");
static_assert(!and_<true_, false_>::type::value, "");
static_assert(!and_<false_, true_>::type::value, "");
static_assert(!and_<false_, false_>::type::value, "");

static_assert(!and_<true_, true_, false_>::type::value, "");
static_assert(and_<true_, true_, true_>::type::value, "");

// Make sure we short-circuit.
static_assert(!and_<false_, struct not_a_metafunction>::type::value, "");
static_assert(!and_<true_, false_, struct not_a_metafunction>::type::value, "");


int main() { }
