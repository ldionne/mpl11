/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::is_permutation`.
 */

#include <boost/mpl11/algorithm/is_permutation.hpp>

#include <boost/mpl11/container/vector.hpp>


using namespace boost::mpl11;
using algorithm::is_permutation;
using container::vector;


static_assert(is_permutation<
    vector<>, vector<>
>::type::value, "");

static_assert(is_permutation<
    vector<int>, vector<int>
>::type::value, "");

static_assert(is_permutation<
    vector<int, float>, vector<int, float>
>::type::value, "");

static_assert(is_permutation<
    vector<float, int>, vector<int, float>
>::type::value, "");

static_assert(is_permutation<
    vector<float, int, char>, vector<int, float, char>
>::type::value, "");

static_assert(is_permutation<
    vector<float, char, int, char, int>, vector<int, int, char, float, char>
>::type::value, "");


int main() { }
