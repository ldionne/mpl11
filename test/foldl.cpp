/*!
 * @file
 * Contains unit tests for `boost::mpl11::foldl`.
 */

#include <boost/mpl11/foldl.hpp>

#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;

template <int> struct x;

template <template <int ...i> class seq>
struct test_one {
    static_assert(equal<
        typename foldl<seq<>, vector<>, quote<push_back>>::type,
        vector<>
    >::value, "");

    static_assert(equal<
        typename foldl<seq<0>, vector<>, quote<push_back>>::type,
        vector<x<0>>
    >::value, "");

    static_assert(equal<
        typename foldl<seq<0, 1>, vector<>, quote<push_back>>::type,
        vector<x<0>, x<1>>
    >::value, "");

    static_assert(equal<
        typename foldl<seq<0, 1, 2>, vector<>, quote<push_back>>::type,
        vector<x<0>, x<1>, x<2>>
    >::value, "");

    static_assert(equal<
        typename foldl<seq<0, 1, 2, 3>, vector<>, quote<push_back>>::type,
        vector<x<0>, x<1>, x<2>, x<3>>
    >::value, "");
};

//! @todo Find a way to test the optimized algorithm.
template <int ...i>
using no_opt = test::wrapper<
    test::minimal_requirements<Sequence>, vector<x<i>...>
>;

struct test_all
    : test_one<no_opt>
{ };


int main() { }
