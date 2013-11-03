/*!
 * @file
 * Contains unit tests for `boost::mpl11::foldl`.
 */

#include <boost/mpl11/foldl.hpp>

#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;

static_assert(equal<
    foldl<vector<>, vector<>, quote<push_back>>::type,
    vector<>
>::value, "");

static_assert(equal<
    foldl<vector_c<int, 0>, vector<>, quote<push_back>>::type,
    vector_c<int, 0>
>::value, "");

static_assert(equal<
    foldl<vector_c<int, 0, 1>, vector<>, quote<push_back>>::type,
    vector_c<int, 0, 1>
>::value, "");

static_assert(equal<
    foldl<vector_c<int, 0, 1, 2>, vector<>, quote<push_back>>::type,
    vector_c<int, 0, 1, 2>
>::value, "");

static_assert(equal<
    foldl<vector_c<int, 0, 1, 2, 3>, vector<>, quote<push_back>>::type,
    vector_c<int, 0, 1, 2, 3>
>::value, "");


int main() { }
