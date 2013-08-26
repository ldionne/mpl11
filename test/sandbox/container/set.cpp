/*!
 * @file
 * This file contains unit tests for `boost::mpl11::set`.
 */

#include <boost/mpl11/container/set.hpp>
#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;

struct k0;
struct k1;

// construction
static_assert(is_same<set<k0, k1>::type, set<k0, k1>>::value, "");


// empty
static_assert(empty<set<>>::value, "");
static_assert(!empty<set<k0>>::value, "");
static_assert(!empty<set<k0, k1>>::value, "");


// size
static_assert(size<set<>>::value == 0, "");
static_assert(size<set<k0>>::value == 1, "");
static_assert(size<set<k0, k1>>::value == 2, "");


// front
static_assert(is_same<front<set<k0>>::type, k0>::value, "");
static_assert(is_same<front<set<k0, k1>>::type, k0>::value, "");


// has_key
static_assert(!has_key<set<>, k0>::value, "");
static_assert(!has_key<set<k1>, k0>::value, "");
static_assert(has_key<set<k0>, k0>::value, "");
static_assert(has_key<set<k0, k1>, k1>::value, "");


// at
struct default_;
static_assert(is_same<at<set<>, k0, default_>::type, default_>::value, "");
static_assert(is_same<at<set<k0>, k0>::type, k0>::value, "");
static_assert(is_same<at<set<k0>, k0, default_>::type, k0>::value, "");
static_assert(is_same<at<set<k0, k1>, k1>::type, k1>::value, "");


// key/value
static_assert(is_same<key<set<>, k0>::type, k0>::value, "");
static_assert(is_same<value<set<>, k0>::type, k0>::value, "");


// clear
static_assert(is_same<clear<set<>>::type, set<>>::value, "");
static_assert(is_same<clear<set<k0>>::type, set<>>::value, "");
static_assert(is_same<clear<set<k0, k1>>::type, set<>>::value, "");


// insert
static_assert(is_same<at<insert<set<>, k0>::type, k0>::type, k0>::value, "");
static_assert(is_same<at<insert<set<k0>, k1>::type, k0>::type, k0>::value, "");
static_assert(is_same<at<insert<set<k0>, k1>::type, k1>::type, k1>::value, "");


// insert with hint (hint is ignored)
static_assert(is_same<
    insert<set<>, k0>::type,
    insert<set<>, struct hint, k0>::type
>::value, "");
static_assert(is_same<
    insert<set<k0>, k1>::type,
    insert<set<k0>, struct hint, k1>::type
>::value, "");


// erase_key (tests erase at the same time)
static_assert(!has_key<erase_key<set<>, k0>::type, k0>::value, "");
static_assert(!has_key<erase_key<set<k1>, k0>::type, k0>::value, "");
static_assert(!has_key<erase_key<set<k0>, k0>::type, k0>::value, "");
static_assert(!has_key<erase_key<set<k0, k1>, k1>::type, k1>::value, "");
static_assert(has_key<erase_key<set<k0, k1>, k1>::type, k0>::value, "");


int main() { }
