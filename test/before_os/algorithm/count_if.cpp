/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::count_if`.
 */

#include <boost/mpl11/count_if.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/vector.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/equal_to.hpp>


using namespace boost::mpl11;
using algorithm::count_if;
using container::vector;


static_assert(count_if<
    vector<>, always<true_>
>::type::value == 0, "");

static_assert(count_if<
    vector<int, char, float>, always<true_>
>::type::value == 3, "");

// Make sure the predicate is not evaluated when the sequence is empty.
static_assert(count_if<
    vector<>, struct not_a_metafunction
>::type::value == 0, "");

// Try with various `LambdaExpression`s.
static_assert(count_if<
    vector<false_, true_, true_>, _1
>::type::value == 2, "");

static_assert(count_if<
    vector<float, int>, equal_to<int, _1>
>::type::value == 1, "");


int main() { }
