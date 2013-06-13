/*!
 * @file
 * This file contains unit tests for `boost::mpl11::map`.
 */

#include <boost/mpl11/container/map.hpp>
#include <boost/mpl11/container/pair.hpp>

#include <boost/type_traits/is_same.hpp>


using namespace boost;
using namespace boost::mpl11;

struct k0; struct v0;
struct k1; struct v1;
struct k2; struct v2;

// construction
static_assert(is_same<
    map<pair<k0, v0>>::type,
    map<pair<k0, v0>>
>::value, "");


// empty
static_assert(empty<map<>>::value, "");
static_assert(!empty<map<pair<k0, v0>>>::value, "");


// size
static_assert(size<map<>>::value == 0, "");
static_assert(size<map<pair<k0, v0>>>::value == 1, "");
static_assert(size<map<pair<k0, v0>, pair<k1, v1>>>::value == 2, "");


// front
static_assert(is_same<
    front<map<pair<k0, v0>>>::type,
    pair<k0, v0>
>::value, "");
static_assert(is_same<
    front<map<pair<k0, v0>, pair<k1, v1>>>::type,
    pair<k0, v0>
>::value, "");


// has_key
static_assert(!has_key<map<>, k0>::value, "");
static_assert(!has_key<map<pair<k1, v1>>, k0>::value, "");
static_assert(has_key<map<pair<k0, v0>>, k0>::value, "");
static_assert(has_key<map<pair<k0, v0>, pair<k1, v1>>, k1>::value, "");


// at
struct default_;
static_assert(is_same<
    at<map<>, k0, default_>::type, default_
>::value, "");
static_assert(is_same<
    at<map<pair<k0, v0>>, k0>::type, v0
>::value, "");
static_assert(is_same<
    at<map<pair<k0, v0>>, k0, default_>::type, v0
>::value, "");
static_assert(is_same<
    at<map<pair<k0, v0>, pair<k1, v1>>, k1>::type, v1
>::value, "");


// key/value
static_assert(is_same<
    key<map<>, pair<k0, v0>>::type, k0
>::value, "");
static_assert(is_same<
    value<map<>, pair<k0, v0>>::type, v0
>::value, "");


// clear
static_assert(is_same<clear<map<>>::type, map<>>::value, "");
static_assert(is_same<clear<map<pair<k0, v0>>>::type, map<>>::value, "");


// insert
static_assert(is_same<
    at<insert<map<>, pair<k0, v0>>::type, k0>::type, v0
>::value, "");
static_assert(is_same<
    at<insert<map<pair<k0, v0>>, pair<k1, v1>>::type, k0>::type, v0
>::value, "");
static_assert(is_same<
    at<insert<map<pair<k0, v0>>, pair<k1, v1>>::type, k1>::type, v1
>::value, "");

// insert with hint (hint is ignored)
static_assert(is_same<
    insert<map<>, pair<k0, v0>>::type,
    insert<map<>, struct hint, pair<k0, v0>>::type
>::value, "");
static_assert(is_same<
    insert<map<pair<k0, v0>>, pair<k1, v1>>::type,
    insert<map<pair<k0, v0>>, struct hint, pair<k1, v1>>::type
>::value, "");


// erase_key (tests erase at the same time)
static_assert(!has_key<erase_key<map<>, k0>::type, k0>::value, "");
static_assert(!has_key<erase_key<map<pair<k1, v1>>, k0>::type, k0>::value, "");
static_assert(!has_key<erase_key<map<pair<k0, v0>>, k0>::type, k0>::value, "");
static_assert(!has_key<erase_key<map<pair<k0, v0>, pair<k1, v1>>, k1>::type, k1>::value, "");


int main() { }
