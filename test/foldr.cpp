/*!
 * @file
 * Contains unit tests for `boost::mpl11::foldr`.
 */

#include <boost/mpl11/foldr.hpp>

#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;

template <int> struct x;
template <int ...i>
using seq = test::wrapper<
    test::minimal_requirements<Sequence>, vector<x<i>...>
>;

static_assert(equal<
    foldr<seq<>, vector<>, quote<push_back>>::type,
    vector<>
>::value, "");

static_assert(equal<
    foldr<seq<0>, vector<>, quote<push_back>>::type,
    vector<x<0>>
>::value, "");

static_assert(equal<
    foldr<seq<0, 1>, vector<>, quote<push_back>>::type,
    vector<x<1>, x<0>>
>::value, "");

static_assert(equal<
    foldr<seq<0, 1, 2>, vector<>, quote<push_back>>::type,
    vector<x<2>, x<1>, x<0>>
>::value, "");

static_assert(equal<
    foldr<seq<0, 1, 2, 3>, vector<>, quote<push_back>>::type,
    vector<x<3>, x<2>, x<1>, x<0>>
>::value, "");


int main() { }
