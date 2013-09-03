/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::contains`.
 */

#include <boost/mpl11/algorithm/contains.hpp>

#include <boost/mpl11/container/vector.hpp>


using namespace boost::mpl11;
using algorithm::contains;
using container::vector;


static_assert(!contains<
    vector<>, int
>::type::value, "");

static_assert(!contains<
    vector<float>, int
>::type::value, "");

static_assert(contains<
    vector<int>, int
>::type::value, "");

static_assert(contains<
    vector<float, int>, int
>::type::value, "");

static_assert(contains<
    vector<float, int, int>, int
>::type::value, "");


int main() { }
