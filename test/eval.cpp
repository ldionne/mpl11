/*!
 * @file
 * This file contains unit tests for `boost::mpl11::eval`.
 */

#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/protect.hpp>

#include <boost/type_traits/is_same.hpp>


using namespace boost;
using namespace boost::mpl11;

template <typename ...> struct pack;

// For normal types, this is just the identity metafunction.
static_assert(is_same<eval<int>::type, int>::value, "");
static_assert(is_same<eval<identity<int>>::type, identity<int>>::value, "");


// When a type nested inside an eval<> is encountered, it is evaluated.
static_assert(is_same<eval<eval<identity<int>>>::type, int>::value, "");
static_assert(is_same<
    eval<pack<float, eval<identity<int>>>>::type,
    pack<float, int>
>::value, "");


// Nested eval<>'s are evaluated recursively.
static_assert(is_same<
    eval<
        eval<    eval<    eval<
        identity<identity<identity<int>>>>>>
    >::type,
    int
>::value, "");


// When something is nested inside a protect<>, it is left alone.
static_assert(is_same<eval<protect<int>>::type, protect<int>>::value, "");
static_assert(is_same<eval<protect<eval<int>>>::type, protect<eval<int>>>::value, "");


// When evaluating a protected expression nested inside an eval<>, it is
// the protect<> is left alone but is then evaluated according to the normal
// rules because it was nested in an eval<>.
static_assert(is_same<
    eval<
        eval<protect<identity<int>>>
    >::type,
    protect<identity<int>>::type // == int
>::value, "");


// Mix genuine eval<> with protect<> in the same pack.
static_assert(is_same<
    eval<pack<eval<identity<int>>, protect<float>>>::type,
    pack<int, protect<float>>
>::value, "");


int main() { }
