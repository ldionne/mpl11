/*!
 * @file
 * Contains unit tests for `boost::mpl11::container::vector`.
 */

#include <boost/mpl11/container/vector.hpp>

#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;
using container::vector;

struct a0; struct a1; struct a2;

#error rewrite in a generic way for all sequences perhaps
// construction
static_assert(is_same<
    vector<a0, a1>::type,
    vector<a0, a1>
>::value, "");


// empty
static_assert(empty<vector<>>::value, "");
static_assert(!empty<vector<a0>>::value, "");


// size
static_assert(size<vector<>>::value == 0, "");
static_assert(size<vector<a0>>::value == 1, "");
static_assert(size<vector<a0, a1>>::value == 2, "");


// front
static_assert(is_same<front<vector<a0>>::type, a0>::value, "");
static_assert(is_same<front<vector<a0, a1>>::type, a0>::value, "");


// back
static_assert(is_same<back<vector<a0>>::type, a0>::value, "");
static_assert(is_same<back<vector<a0, a1>>::type, a1>::value, "");


// clear
static_assert(is_same<clear<vector<>>::type, vector<>>::value, "");
static_assert(is_same<clear<vector<a0>>::type, vector<>>::value, "");
static_assert(is_same<clear<vector<a0, a1>>::type, vector<>>::value, "");


// push_front
static_assert(is_same<push_front<vector<>, a0>::type, vector<a0>>::value, "");
static_assert(is_same<push_front<vector<a1>, a0>::type, vector<a0, a1>>::value, "");
static_assert(is_same<push_front<vector<a1, a2>, a0>::type, vector<a0, a1, a2>>::value, "");


// push_back
static_assert(is_same<push_back<vector<>, a0>::type, vector<a0>>::value, "");
static_assert(is_same<push_back<vector<a0>, a1>::type, vector<a0, a1>>::value, "");
static_assert(is_same<push_back<vector<a0, a1>, a2>::type, vector<a0, a1, a2>>::value, "");


// pop_back
static_assert(is_same<pop_back<vector<a0>>::type, vector<>>::value, "");
static_assert(is_same<pop_back<vector<a0, a1>>::type, vector<a0>>::value, "");


// pop_front
static_assert(is_same<pop_front<vector<a0>>::type, vector<>>::value, "");
static_assert(is_same<pop_front<vector<a0, a1>>::type, vector<a1>>::value, "");


// at/at_c
static_assert(is_same<at_c<vector<a0>, 0>::type, a0>::value, "");
static_assert(is_same<at_c<vector<a0, a1>, 0>::type, a0>::value, "");
static_assert(is_same<at_c<vector<a0, a1>, 1>::type, a1>::value, "");


// begin/end
static_assert(is_same<begin<vector<>>::type, end<vector<>>::type>::value, "");
static_assert(!is_same<begin<vector<a0>>::type, end<vector<a0>>::type>::value, "");
static_assert(!is_same<end<vector<a0>>::type, end<vector<>>::type>::value, "");


// next/prior
static_assert(is_same<
    next<begin<vector<a0>>::type>::type,
    end<vector<a0>>::type
>::value, "");
static_assert(is_same<
    prior<end<vector<a0>>::type>::type,
    begin<vector<a0>>::type
>::value, "");


// deref
static_assert(is_same<deref<begin<vector<a0>>::type>::type, a0>::value, "");


int main() { }
