/*!
 * @file
 * This file contains unit tests for `boost::mpl11::eval`.
 */

#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/has_xxx.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/protect.hpp>


using namespace boost::mpl11;

template <typename ...> struct pack;
template <typename ...T> struct make_pack { using type = pack<T...>; };

// `eval` evaluates its metafunction argument once.
static_assert(is_same<
    eval<identity<int>>::type,
    identity<int>::type,
    int
>::value, "");


// For non-metafunction types, it should not have a nested `type`.
BOOST_MPL11_HAS_NESTED_TYPE(has_type, type)
static_assert(!has_type<eval<int>>::value, "");
static_assert(!has_type<eval<pack<>>>::value, "");


// When a type nested inside an `eval<>` is encountered, it is replaced by
// the result of evaluating what's inside the `eval<>`, after evaluating it
// recursively. However, only what is nested inside an `eval<>` is evaluated
// and anything else is left as-is.
static_assert(is_same< // unary template
    eval<make_pack<eval<identity<int>>>>::type,
    eval<make_pack<identity<int>::type>>::type,
    eval<make_pack<int>>::type,
    make_pack<int>::type,
    pack<int>
>::value, "");
static_assert(is_same< // binary template
    eval<make_pack<float, eval<identity<int>>>>::type,
    eval<make_pack<float, identity<int>::type>>::type,
    eval<make_pack<float, int>>::type,
    make_pack<float, int>::type,
    pack<float, int>
>::value, "");
static_assert(is_same< // nested evals
    eval<eval<eval<identity<identity<identity<int>>>>>>::type,
    eval<eval<identity<identity<identity<int>>>::type>>::type,
    eval<eval<identity<identity<int>>>>::type,
    eval<identity<identity<int>>::type>::type,
    eval<identity<int>>::type,
    identity<int>::type,
    int
>::value, "");
static_assert(is_same< // "hidden" nested eval
    eval<make_pack<int, pack<eval<identity<float>>>>>::type,
    eval<make_pack<int, pack<identity<float>::type>>>::type,
    eval<make_pack<int, pack<float>>>::type,
    make_pack<int, pack<float>>::type,
    pack<int, pack<float>>
>::value, "");


// `protect`s are left alone.
static_assert(is_same<
    eval<make_pack<int, protect<eval<float>>>>::type,
    make_pack<int, protect<eval<float>>>::type,
    pack<int, protect<eval<float>>>
>::value, "");


// However, `protect`s are evaluated like the rest when requested.
static_assert(is_same<
    eval<make_pack<int, eval<protect<identity<float>>>>>::type,
    eval<make_pack<int, protect<identity<float>>::type>>::type,
    eval<make_pack<int, identity<float>::type>>::type,
    eval<make_pack<int, float>>::type,
    make_pack<int, float>::type,
    pack<int, float>
>::value, "");
static_assert(is_same<
    eval<protect<identity<eval<int>>>>::type,
    protect<identity<eval<int>>>::type,
    identity<eval<int>>::type,
    eval<int>
>::value, "");
static_assert(is_same<
    eval<protect<eval<identity<int>>>>::type,
    protect<eval<identity<int>>>::type,
    eval<identity<int>>::type,
    identity<int>::type,
    int
>::value, "");


// Mix genuine eval<> with protect<> in the same pack.
static_assert(is_same<
    eval<make_pack<eval<identity<int>>, protect<float>>>::type,
    eval<make_pack<identity<int>::type, protect<float>>>::type,
    eval<make_pack<int, protect<float>>>::type,
    make_pack<int, protect<float>>::type,
    pack<int, protect<float>>
>::value, "");


int main() { }
