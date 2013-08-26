/*!
 * @file
 * This file contains unit tests for `boost::mpl11::variadic`.
 */

#include <boost/mpl11/container/variadic.hpp>
#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;

struct a0;
struct a1;
struct a2;

template <typename ...> struct pack;

// construction
static_assert(is_same<
    variadic<pack<a0, a1>>::type,
    variadic<pack<a0, a1>>
>::value, "");


// empty
static_assert(empty<variadic<pack<>>>::value, "");
static_assert(!empty<variadic<pack<a0>>>::value, "");


// size
static_assert(size<variadic<pack<>>>::value == 0, "");
static_assert(size<variadic<pack<a0>>>::value == 1, "");
static_assert(size<variadic<pack<a0, a1>>>::value == 2, "");


// front
static_assert(is_same<front<variadic<pack<a0>>>::type, a0>::value, "");
static_assert(is_same<front<variadic<pack<a0, a1>>>::type, a0>::value, "");


// back
static_assert(is_same<back<variadic<pack<a0>>>::type, a0>::value, "");
static_assert(is_same<back<variadic<pack<a0, a1>>>::type, a1>::value, "");


// clear
static_assert(is_same<clear<variadic<pack<>>>::type, pack<>>::value, "");
static_assert(is_same<clear<variadic<pack<a0>>>::type, pack<>>::value, "");
static_assert(is_same<clear<variadic<pack<a0, a1>>>::type, pack<>>::value, "");


// push_front
static_assert(is_same<push_front<variadic<pack<>>, a0>::type, pack<a0>>::value, "");
static_assert(is_same<push_front<variadic<pack<a1>>, a0>::type, pack<a0, a1>>::value, "");
static_assert(is_same<push_front<variadic<pack<a1, a2>>, a0>::type, pack<a0, a1, a2>>::value, "");


// push_back
static_assert(is_same<push_back<variadic<pack<>>, a0>::type, pack<a0>>::value, "");
static_assert(is_same<push_back<variadic<pack<a0>>, a1>::type, pack<a0, a1>>::value, "");
static_assert(is_same<push_back<variadic<pack<a0, a1>>, a2>::type, pack<a0, a1, a2>>::value, "");


// pop_back
static_assert(is_same<pop_back<variadic<pack<a0>>>::type, pack<>>::value, "");
static_assert(is_same<pop_back<variadic<pack<a0, a1>>>::type, pack<a0>>::value, "");


// pop_front
static_assert(is_same<pop_front<variadic<pack<a0>>>::type, pack<>>::value, "");
static_assert(is_same<pop_front<variadic<pack<a0, a1>>>::type, pack<a1>>::value, "");


// at/at_c
static_assert(is_same<at_c<variadic<pack<a0>>, 0>::type, a0>::value, "");
static_assert(is_same<at_c<variadic<pack<a0, a1>>, 0>::type, a0>::value, "");
static_assert(is_same<at_c<variadic<pack<a0, a1>>, 1>::type, a1>::value, "");


// begin/end
static_assert(is_same<begin<variadic<pack<>>>::type, end<variadic<pack<>>>::type>::value, "");
static_assert(!is_same<begin<variadic<pack<a0>>>::type, end<variadic<pack<a0>>>::type>::value, "");
static_assert(!is_same<end<variadic<pack<a0>>>::type, end<variadic<pack<>>>::type>::value, "");
static_assert(!is_same<begin<variadic<pack<>>>::type, begin<vector<>>::type>::value, "");
static_assert(!is_same<end<variadic<pack<>>>::type, end<vector<>>::type>::value, "");


// next/prior
static_assert(is_same<
    next<begin<variadic<pack<a0>>>::type>::type,
    end<variadic<pack<a0>>>::type
>::value, "");
static_assert(is_same<
    prior<end<variadic<pack<a0>>>::type>::type,
    begin<variadic<pack<a0>>>::type
>::value, "");


// deref
static_assert(is_same<deref<begin<variadic<pack<a0>>>::type>::type, a0>::value, "");


int main() { }
