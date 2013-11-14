/*!
 * @file
 * Contains unit tests for `boost::mpl11::imap`.
 */

#include <boost/mpl11/imap.hpp>

#include <boost/mpl11/at_key.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/erase_key.hpp>
#include <boost/mpl11/has_key.hpp>
#include <boost/mpl11/insert_key.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/pair.hpp>
#include <boost/mpl11/value_of.hpp>


using namespace boost::mpl11;
using detail::is_same;
using imap_detail::iterator;

template <int> struct key;
template <int> struct value;
template <int k, int v> using kv = pair<key<k>, value<v>>;


/////////////////////
// test the iterator
/////////////////////
// next
static_assert(is_same<
    next<iterator<kv<0, 0>>>::type,
    iterator<>
>::value, "");
static_assert(is_same<
    next<iterator<kv<0, 0>, kv<1, 1>>>::type,
    iterator<kv<1, 1>>
>::value, "");


// equal
static_assert( equal<iterator<>, iterator<>>::value, "");
static_assert(!equal<iterator<kv<0, 0>>, iterator<>>::value, "");
static_assert(!equal<iterator<>, iterator<kv<0, 0>>>::value, "");
static_assert( equal<iterator<kv<0, 0>>, iterator<kv<0, 0>>>::value, "");
static_assert(!equal<iterator<kv<0, 0>>, iterator<kv<1, 1>>>::value, "");
static_assert(!equal<iterator<kv<0, 0>>, iterator<kv<0, 0>, kv<1, 1>>>::value, "");


// deref
static_assert(is_same<
    deref<iterator<kv<0, 0>>>::type,
    kv<0, 0>
>::value, "");
static_assert(is_same<
    deref<iterator<kv<0, 0>, kv<1, 1>>>::type,
    kv<0, 0>
>::value, "");


/////////////////////
// test the imap
/////////////////////
// begin
static_assert(is_same<
    begin<imap<>>::type,
    iterator<>
>::value, "");
static_assert(is_same<
    begin<imap<kv<0, 0>>>::type,
    iterator<kv<0, 0>>
>::value, "");
static_assert(is_same<
    begin<imap<kv<0, 0>, kv<1, 1>>>::type,
    iterator<kv<0, 0>, kv<1, 1>>
>::value, "");

// end
static_assert(is_same<
    end<imap<>>::type,
    iterator<>
>::value, "");
static_assert(is_same<
    end<imap<kv<0, 0>>>::type,
    iterator<>
>::value, "");
static_assert(is_same<
    end<imap<kv<0, 0>, kv<1, 1>>>::type,
    iterator<>
>::value, "");


// at_key (without default)
static_assert(is_same<
    at_key<imap<kv<0, 0>>, key<0>>::type,
    value<0>
>::value, "");

static_assert(is_same<
    at_key<imap<kv<0, 0>, kv<1, 1>>, key<0>>::type,
    value<0>
>::value, "");
static_assert(is_same<
    at_key<imap<kv<0, 0>, kv<1, 1>>, key<1>>::type,
    value<1>
>::value, "");

static_assert(is_same<
    at_key<imap<kv<0, 0>, kv<1, 1>, kv<2, 2>>, key<0>>::type,
    value<0>
>::value, "");
static_assert(is_same<
    at_key<imap<kv<0, 0>, kv<1, 1>, kv<2, 2>>, key<1>>::type,
    value<1>
>::value, "");
static_assert(is_same<
    at_key<imap<kv<0, 0>, kv<1, 1>, kv<2, 2>>, key<2>>::type,
    value<2>
>::value, "");


// at_key (with default)
struct default_;
static_assert(is_same<
    at_key<imap<>, key<0>, default_>::type,
    default_
>::value, "");

static_assert(is_same<
    at_key<imap<kv<0, 0>>, key<0>, default_>::type,
    value<0>
>::value, "");
static_assert(is_same<
    at_key<imap<kv<0, 0>>, key<1>, default_>::type,
    default_
>::value, "");

static_assert(is_same<
    at_key<imap<kv<0, 0>, kv<1, 1>>, key<0>, default_>::type,
    value<0>
>::value, "");
static_assert(is_same<
    at_key<imap<kv<0, 0>, kv<1, 1>>, key<1>, default_>::type,
    value<1>
>::value, "");
static_assert(is_same<
    at_key<imap<kv<0, 0>, kv<1, 1>>, key<2>, default_>::type,
    default_
>::value, "");


// has_key
static_assert(!has_key<imap<>, key<0>>::value, "");

static_assert( has_key<imap<kv<0, 0>>, key<0>>::value, "");
static_assert(!has_key<imap<kv<0, 0>>, key<1>>::value, "");

static_assert( has_key<imap<kv<0, 0>, kv<1, 1>>, key<0>>::value, "");
static_assert( has_key<imap<kv<0, 0>, kv<1, 1>>, key<1>>::value, "");
static_assert(!has_key<imap<kv<0, 0>, kv<1, 1>>, key<2>>::value, "");

static_assert( has_key<imap<kv<0, 0>, kv<1, 1>, kv<2, 2>>, key<0>>::value, "");
static_assert( has_key<imap<kv<0, 0>, kv<1, 1>, kv<2, 2>>, key<1>>::value, "");
static_assert( has_key<imap<kv<0, 0>, kv<1, 1>, kv<2, 2>>, key<2>>::value, "");
static_assert(!has_key<imap<kv<0, 0>, kv<1, 1>, kv<2, 2>>, key<3>>::value, "");


// key_of
static_assert(is_same<
    key_of<imap<>, kv<0, 0>>::type,
    key<0>
>::value, "");
static_assert(is_same<
    key_of<imap<kv<0, 0>>, kv<0, 0>>::type,
    key<0>
>::value, "");
static_assert(is_same<
    key_of<imap<kv<1, 1>>, kv<0, 0>>::type,
    key<0>
>::value, "");


// value_of
static_assert(is_same<
    value_of<imap<>, kv<0, 0>>::type,
    value<0>
>::value, "");
static_assert(is_same<
    value_of<imap<kv<0, 0>>, kv<0, 0>>::type,
    value<0>
>::value, "");
static_assert(is_same<
    value_of<imap<kv<1, 1>>, kv<0, 0>>::type,
    value<0>
>::value, "");


// new
//! @todo Write a unit test for this once its semantics are fixed.

// clear
static_assert(is_same<
    clear<imap<>>::type, imap<>
>::value, "");
static_assert(is_same<
    clear<imap<kv<0, 0>>>::type, imap<>
>::value, "");
static_assert(is_same<
    clear<imap<kv<0, 0>, kv<1, 1>>>::type, imap<>
>::value, "");


// insert_key
static_assert(equal<
    insert_key<imap<>, kv<0, 0>>::type,
    imap<kv<0, 0>>
>::value, "");

static_assert(equal<
    insert_key<imap<kv<0, 0>>, kv<0, 0>>::type,
    imap<kv<0, 0>>
>::value, "");
static_assert(equal<
    insert_key<imap<kv<0, 0>>, kv<0, 1>>::type,
    imap<kv<0, 1>>
>::value, "");
static_assert(equal<
    insert_key<imap<kv<0, 0>>, kv<1, 1>>::type,
    imap<kv<0, 0>, kv<1, 1>>
>::value, "");

static_assert(equal<
    insert_key<imap<kv<0, 0>, kv<1, 1>>, kv<0, 0>>::type,
    imap<kv<0, 0>, kv<1, 1>>
>::value, "");
static_assert(equal<
    insert_key<imap<kv<0, 0>, kv<1, 1>>, kv<0, 1>>::type,
    imap<kv<0, 1>, kv<1, 1>>
>::value, "");
static_assert(equal<
    insert_key<imap<kv<0, 0>, kv<1, 1>>, kv<1, 1>>::type,
    imap<kv<0, 0>, kv<1, 1>>
>::value, "");
static_assert(equal<
    insert_key<imap<kv<0, 0>, kv<1, 1>>, kv<1, 2>>::type,
    imap<kv<0, 0>, kv<1, 2>>
>::value, "");
static_assert(equal<
    insert_key<imap<kv<0, 0>, kv<1, 1>>, kv<2, 2>>::type,
    imap<kv<0, 0>, kv<1, 1>, kv<2, 2>>
>::value, "");


// erase_key
static_assert(equal<
    erase_key<imap<>, key<0>>::type,
    imap<>
>::value, "");

static_assert(equal<
    erase_key<imap<kv<0, 0>>, key<0>>::type,
    imap<>
>::value, "");
static_assert(equal<
    erase_key<imap<kv<0, 0>>, key<1>>::type,
    imap<kv<0, 0>>
>::value, "");

static_assert(equal<
    erase_key<imap<kv<0, 0>, kv<1, 1>>, key<0>>::type,
    imap<kv<1, 1>>
>::value, "");
static_assert(equal<
    erase_key<imap<kv<0, 0>, kv<1, 1>>, key<1>>::type,
    imap<kv<0, 0>>
>::value, "");
static_assert(equal<
    erase_key<imap<kv<0, 0>, kv<1, 1>>, key<2>>::type,
    imap<kv<0, 0>, kv<1, 1>>
>::value, "");


int main() { }
