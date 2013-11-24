/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::eager_any` and
 * `boost::mpl11::detail::eager_any_c`.
 */

#include <boost/mpl11/detail/eager_any.hpp>

#include <boost/mpl11/integral_c.hpp>


using namespace boost::mpl11;
using detail::eager_any;

static_assert(!eager_any<>::value, "");

static_assert( eager_any<true_>::value, "");
static_assert(!eager_any<false_>::value, "");

static_assert( eager_any<true_, true_>::value, "");
static_assert( eager_any<true_, false_>::value, "");
static_assert( eager_any<false_, true_>::value, "");
static_assert(!eager_any<false_, false_>::value, "");

static_assert( eager_any<true_, true_, true_>::value, "");
static_assert( eager_any<true_, true_, false_>::value, "");
static_assert( eager_any<true_, false_, true_>::value, "");
static_assert( eager_any<true_, false_, false_>::value, "");

static_assert( eager_any<false_, true_, true_>::value, "");
static_assert( eager_any<false_, true_, false_>::value, "");
static_assert( eager_any<false_, false_, true_>::value, "");
static_assert(!eager_any<false_, false_, false_>::value, "");


int main() { }
