/*!
 * @file
 * Contains unit tests for `boost::mpl11::foldr`.
 */

#include <boost/mpl11/foldr.hpp>

#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;

static_assert(equal<
    foldr<vector<>, vector<>, quote<push_back>>::type,
    vector<>
>::value, "");

static_assert(equal<
    foldr<vector_c<int, 0>, vector<>, quote<push_back>>::type,
    vector_c<int, 0>
>::value, "");

static_assert(equal<
    foldr<vector_c<int, 0, 1>, vector<>, quote<push_back>>::type,
    vector_c<int, 1, 0>
>::value, "");

static_assert(equal<
    foldr<vector_c<int, 0, 1, 2>, vector<>, quote<push_back>>::type,
    vector_c<int, 2, 1, 0>
>::value, "");

static_assert(equal<
    foldr<vector_c<int, 0, 1, 2, 3>, vector<>, quote<push_back>>::type,
    vector_c<int, 3, 2, 1, 0>
>::value, "");


int main() { }
