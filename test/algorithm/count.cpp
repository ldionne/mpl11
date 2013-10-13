/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::count`.
 */

#include <boost/mpl11/count.hpp>

#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using algorithm::count;
using container::vector;


static_assert(count<
    vector<>, int
>::type::value == 0, "");

static_assert(count<
    vector<float>, int
>::type::value == 0, "");

static_assert(count<
    vector<int>, int
>::type::value == 1, "");

static_assert(count<
    vector<int, int>, int
>::type::value == 2, "");

static_assert(count<
    vector<int, float>, int
>::type::value == 1, "");

static_assert(count<
    vector<float, int>, int
>::type::value == 1, "");

static_assert(count<
    vector<float, int, char, int, void>, int
>::type::value == 2, "");


int main() { }
