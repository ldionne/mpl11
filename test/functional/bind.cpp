/*!
 * @file
 * This file contains unit tests for `boost::mpl11::bind`.
 */

#include <boost/mpl11/functional/bind.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/functional/protect.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;

template <typename ...> struct pack;
template <typename ...T> struct make_pack { using type = pack<T...>; };

// nested `binds`
static_assert(is_same<
    apply_raw<
        bind<quote<make_pack>, _2, bind<quote<make_pack>, char, _1>>,
        int, float
    >::type,
    make_pack<float, make_pack<char, int>::type>::type,
    pack<float, pack<char, int>>
>::value, "");


// nested `bind`s with protect
static_assert(is_same<
    apply_raw<
        bind<quote<make_pack>, _2, protect<bind<quote<make_pack>, char, _1>>>,
        int, float
    >::type,
    make_pack<float, protect<bind<quote<make_pack>, char, _1>>>::type,
    pack<float, protect<bind<quote<make_pack>, char, _1>>>
>::value, "");


int main() { }
