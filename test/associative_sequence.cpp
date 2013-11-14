/*!
 * @file
 * Contains unit tests for `boost::mpl11::AssociativeSequence`.
 */

#include <boost/mpl11/associative_sequence.hpp>

#include <boost/mpl11/at_key.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/imap.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/pair.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;
using detail::is_same;

template <int i>
using k = test::wrapper<
    test::minimal_requirements<Comparable>, int_<i>
>;

template <int i>
using v = k<i>;

template <int key, int value>
using kv = pair<k<key>, v<value>>;

template <typename ...Elements>
using sequence = test::wrapper<
    test::minimal_requirements<AssociativeSequence>,
    imap<Elements...>
>;

// equal
static_assert(equal<
    sequence<>,
    sequence<>
>::value, "");
static_assert(!equal<
    sequence<>,
    sequence<kv<0, 0>>
>::value, "");
static_assert(!equal<
    sequence<>,
    sequence<kv<0, 0>, kv<1, 1>>
>::value, "");

static_assert(!equal<
    sequence<kv<0, 0>>,
    sequence<>
>::value, "");
static_assert(equal<
    sequence<kv<0, 0>>,
    sequence<kv<0, 0>>
>::value, "");
static_assert(!equal<
    sequence<kv<0, 0>>,
    sequence<kv<1, 0>>
>::value, "");
static_assert(!equal<
    sequence<kv<0, 0>>,
    sequence<kv<0, 1>>
>::value, "");
static_assert(!equal<
    sequence<kv<0, 0>>,
    sequence<kv<0, 0>, kv<1, 1>>
>::value, "");
static_assert(!equal<
    sequence<kv<0, 0>>,
    sequence<kv<0, 0>, kv<1, 1>>
>::value, "");

static_assert(!equal<
    sequence<kv<0, 0>, kv<1, 1>>,
    sequence<>
>::value, "");
static_assert(!equal<
    sequence<kv<0, 0>, kv<1, 1>>,
    sequence<kv<0, 0>>
>::value, "");
static_assert(equal<
    sequence<kv<0, 0>, kv<1, 1>>,
    sequence<kv<0, 0>, kv<1, 1>>
>::value, "");
static_assert(equal<
    sequence<kv<0, 0>, kv<1, 1>>,
    sequence<kv<1, 1>, kv<0, 0>>
>::value, "");
static_assert(!equal<
    sequence<kv<0, 0>, kv<1, 1>>,
    sequence<kv<0, 2>, kv<1, 1>>
>::value, "");
static_assert(!equal<
    sequence<kv<0, 0>, kv<1, 1>>,
    sequence<kv<0, 0>, kv<1, 1>, kv<2, 2>>
>::value, "");

// Both sequences contain kv<0-9> in different orders.
static_assert(equal<
    sequence<
        kv<5, 5>,
        kv<8, 8>,
        kv<0, 0>,
        kv<6, 6>,
        kv<2, 2>,
        kv<4, 4>,
        kv<7, 7>,
        kv<3, 3>,
        kv<1, 1>,
        kv<9, 9>
    >,
    sequence<
        kv<6, 6>,
        kv<3, 3>,
        kv<8, 8>,
        kv<0, 0>,
        kv<5, 5>,
        kv<7, 7>,
        kv<9, 9>,
        kv<2, 2>,
        kv<1, 1>,
        kv<4, 4>
    >
>::value, "");


// at_key (without default)
static_assert(is_same<
    at_key<sequence<kv<0, 0>>, k<0>>::type, v<0>
>::value, "");

static_assert(is_same<
    at_key<sequence<kv<0, 0>, kv<1, 1>>, k<0>>::type, v<0>
>::value, "");
static_assert(is_same<
    at_key<sequence<kv<0, 0>, kv<1, 1>>, k<1>>::type, v<1>
>::value, "");

static_assert(is_same<
    at_key<sequence<kv<0, 0>, kv<1, 1>, kv<2, 2>>, k<0>>::type, v<0>
>::value, "");
static_assert(is_same<
    at_key<sequence<kv<0, 0>, kv<1, 1>, kv<2, 2>>, k<1>>::type, v<1>
>::value, "");
static_assert(is_same<
    at_key<sequence<kv<0, 0>, kv<1, 1>, kv<2, 2>>, k<2>>::type, v<2>
>::value, "");


int main() { }
