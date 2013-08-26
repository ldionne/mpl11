/*!
 * @file
 * This file contains unit tests for `boost::mpl11::args`.
 */

#include <boost/mpl11/functional/args.hpp>
#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;

template <typename ...> struct pack;
template <typename ...T> struct make_pack { using type = pack<T...>; };
static_assert(is_same<
    apply<make_pack<args<>>, int, float, char>::type,
    make_pack<int, float, char>::type,
    pack<int, float, char>
>::value, "");

static_assert(is_same<
    apply<make_pack<args<1>>, int, float, char>::type,
    make_pack<float, char>::type,
    pack<float, char>
>::value, "");

static_assert(is_same<
    apply<make_pack<args<0, 2>>, int, float, char>::type,
    make_pack<int, float>::type,
    pack<int, float>
>::value, "");

static_assert(is_same<
    apply<make_pack<args<1, 1>>, int, float, char>::type,
    make_pack<>::type,
    pack<>
>::value, "");


int main() { }
