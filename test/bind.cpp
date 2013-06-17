/*!
 * @file
 * This file contains unit tests for `boost::mpl11::bind`.
 */

#include <boost/mpl11/bind.hpp>
#include <boost/mpl11/apply_raw.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/named_argument.hpp>
#include <boost/mpl11/placeholders.hpp>
#include <boost/mpl11/protect.hpp>
#include <boost/mpl11/quote.hpp>


using namespace boost::mpl11;

// bind with positional placeholders
static_assert(is_same<
    apply_raw<bind<quote<identity>, _1>, int>::type,
    apply_raw<quote<identity>, int>::type,
    identity<int>::type,
    int
>::value, "");
static_assert(is_same<
    apply_raw<bind<quote<identity>, _1>, int, float>::type,
    apply_raw<bind<quote<identity>, _1>, int>::type
>::value, "");
static_assert(is_same<
    apply_raw<bind<quote<identity>, _2>, int, float>::type,
    apply_raw<quote<identity>, float>::type,
    identity<float>::type,
    float
>::value, "");


// bind with named placeholders
static_assert(is_same<
    apply_raw<
        bind<quote<identity>, kwarg<struct tag>>,
        named_argument<struct tag, int>
    >::type,
    apply_raw<quote<identity>, int>::type,
    identity<int>::type,
    int
>::value, "");
static_assert(is_same<
    apply_raw<
        bind<quote<identity>, kwarg<struct float_tag>>,
        named_argument<struct int_tag, int>,
        named_argument<struct float_tag, float>
    >::type,
    apply_raw<quote<identity>, float>::type,
    identity<float>::type,
    float
>::value, "");


// bind with the special args placeholder
template <typename ...> struct pack;
template <typename ...T> struct make_pack { using type = pack<T...>; };
static_assert(is_same<
    apply_raw<bind<quote<make_pack>, args<>>, int, float, char>::type,
    apply_raw<quote<make_pack>, int, float, char>::type,
    make_pack<int, float, char>::type,
    pack<int, float, char>
>::value, "");
static_assert(is_same<
    apply_raw<bind<quote<make_pack>, args<1>>, int, float, char>::type,
    apply_raw<quote<make_pack>, float, char>::type,
    make_pack<float, char>::type,
    pack<float, char>
>::value, "");
static_assert(is_same<
    apply_raw<bind<quote<make_pack>, args<0, 2>>, int, float, char>::type,
    apply_raw<quote<make_pack>, int, float>::type,
    make_pack<int, float>::type,
    pack<int, float>
>::value, "");
static_assert(is_same<
    apply_raw<bind<quote<make_pack>, args<1, 1>>, int, float, char>::type,
    apply_raw<quote<make_pack>>::type,
    make_pack<>::type,
    pack<>
>::value, "");


// nested bind's
static_assert(is_same<
    apply_raw<
        bind<quote<make_pack>, _2, bind<quote<make_pack>, char, _1>>,
        int, float
    >::type,
    make_pack<float, make_pack<char, int>::type>::type,
    pack<float, pack<char, int>>
>::value, "");


// nested bind's with protect
static_assert(is_same<
    apply_raw<
        bind<quote<make_pack>, _2, protect<bind<quote<make_pack>, char, _1>>>,
        int, float
    >::type,
    make_pack<float, protect<bind<quote<make_pack>, char, _1>>>::type,
    pack<float, protect<bind<quote<make_pack>, char, _1>>>
>::value, "");


int main() { }
