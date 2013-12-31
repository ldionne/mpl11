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

template <int ...i>
using sequence = test::wrapper<
    test::minimal_requirements<Sequence>, vector<x<i>...>
>;

template <int ...i>
struct test_with {
    static_assert(equal<
        foldl_t<sequence<i...>, vector<>, quote<push_back>>,
        vector<x<i>...>
    >::value, "");
};

struct tests :
    test_with<>,
    test_with<0>,
    test_with<0, 1>,
    test_with<0, 1, 2>,
    test_with<0, 1, 2, 3>,
    test_with<0, 1, 2, 3, 4>,
    test_with<0, 1, 2, 3, 4, 5>,
    test_with<0, 1, 2, 3, 4, 5, 6>,
    test_with<0, 1, 2, 3, 4, 5, 6, 7>,
    test_with<0, 1, 2, 3, 4, 5, 6, 7, 8>,
    test_with<0, 1, 2, 3, 4, 5, 6, 7, 8, 9>
{ };


int main() { }
