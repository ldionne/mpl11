/*!
 * @file
 * Contains unit tests for `boost::mpl11::hset`.
 */

#include <boost/mpl11/hset.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/at_key.hpp>
#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/erase_key.hpp>
#include <boost/mpl11/erase_keys.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/has_key.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/insert_key.hpp>
#include <boost/mpl11/insert_keys.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/value_of.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;
using detail::is_same;

//! @todo Use a minimal Hashable and Comparable here.
template <int> struct k {
    struct mpl_class : Comparable {
        template <typename>
        struct hash_impl { struct type; };

        template <typename Self, typename Other>
        using equal_impl = is_same<Self, Other>;
    };
};

template <int ...i>
using seq = test::wrapper<
    test::minimal_requirements<Sequence>, vector<k<i>...>
>;

template <typename MakeHSet>
struct test_one {
    template <typename ...Elements>
    using hset = apply_t<MakeHSet, vector<Elements...>>;

    // begin


    // end


    // at_key (without default)
    static_assert(is_same<
        typename at_key<hset<k<0>>, k<0>>::type,
        k<0>
    >::value, "");

    static_assert(is_same<
        typename at_key<hset<k<0>, k<1>>, k<0>>::type,
        k<0>
    >::value, "");
    static_assert(is_same<
        typename at_key<hset<k<0>, k<1>>, k<1>>::type,
        k<1>
    >::value, "");

    static_assert(is_same<
        typename at_key<hset<k<0>, k<1>, k<2>>, k<0>>::type,
        k<0>
    >::value, "");
    static_assert(is_same<
        typename at_key<hset<k<0>, k<1>, k<2>>, k<1>>::type,
        k<1>
    >::value, "");
    static_assert(is_same<
        typename at_key<hset<k<0>, k<1>, k<2>>, k<2>>::type,
        k<2>
    >::value, "");


    // at_key (with default)
    struct default_;
    static_assert(is_same<
        typename at_key<hset<>, k<0>, identity<default_>>::type,
        default_
    >::value, "");

    static_assert(is_same<
        typename at_key<hset<k<0>>, k<0>, identity<default_>>::type,
        k<0>
    >::value, "");
    static_assert(is_same<
        typename at_key<hset<k<0>>, k<1>, identity<default_>>::type,
        default_
    >::value, "");

    static_assert(is_same<
        typename at_key<hset<k<0>, k<1>>, k<0>, identity<default_>>::type,
        k<0>
    >::value, "");
    static_assert(is_same<
        typename at_key<hset<k<0>, k<1>>, k<1>, identity<default_>>::type,
        k<1>
    >::value, "");
    static_assert(is_same<
        typename at_key<hset<k<0>, k<1>>, k<2>, identity<default_>>::type,
        default_
    >::value, "");


    // has_key
    static_assert(!has_key<hset<>, k<0>>::value, "");

    static_assert( has_key<hset<k<0>>, k<0>>::value, "");
    static_assert(!has_key<hset<k<0>>, k<1>>::value, "");

    static_assert( has_key<hset<k<0>, k<1>>, k<0>>::value, "");
    static_assert( has_key<hset<k<0>, k<1>>, k<1>>::value, "");
    static_assert(!has_key<hset<k<0>, k<1>>, k<2>>::value, "");

    static_assert( has_key<hset<k<0>, k<1>, k<2>>, k<0>>::value, "");
    static_assert( has_key<hset<k<0>, k<1>, k<2>>, k<1>>::value, "");
    static_assert( has_key<hset<k<0>, k<1>, k<2>>, k<2>>::value, "");
    static_assert(!has_key<hset<k<0>, k<1>, k<2>>, k<3>>::value, "");


    // key_of
    static_assert(is_same<
        typename key_of<hset<>, k<0>>::type,
        k<0>
    >::value, "");
    static_assert(is_same<
        typename key_of<hset<k<0>>, k<0>>::type,
        k<0>
    >::value, "");
    static_assert(is_same<
        typename key_of<hset<k<1>>, k<0>>::type,
        k<0>
    >::value, "");


    // value_of
    static_assert(is_same<
        typename value_of<hset<>, k<0>>::type,
        k<0>
    >::value, "");
    static_assert(is_same<
        typename value_of<hset<k<0>>, k<0>>::type,
        k<0>
    >::value, "");
    static_assert(is_same<
        typename value_of<hset<k<1>>, k<0>>::type,
        k<0>
    >::value, "");


    // new


    // clear
    static_assert(equal<
        typename clear<hset<>>::type, hset<>
    >::value, "");
    static_assert(equal<
        typename clear<hset<k<0>>>::type, hset<>
    >::value, "");
    static_assert(equal<
        typename clear<hset<k<0>, k<1>>>::type, hset<>
    >::value, "");


    // insert_keys
    static_assert(equal<
        typename insert_keys<hset<>, seq<>>::type,
        hset<>
    >::value, "");
    static_assert(equal<
        typename insert_keys<hset<>, seq<0>>::type,
        hset<k<0>>
    >::value, "");
    static_assert(equal<
        typename insert_keys<hset<>, seq<0, 0>>::type,
        hset<k<0>>
    >::value, "");
    static_assert(equal<
        typename insert_keys<hset<>, seq<0, 1>>::type,
        hset<k<0>, k<1>>
    >::value, "");

    static_assert(equal<
        typename insert_keys<hset<k<0>>, seq<>>::type,
        hset<k<0>>
    >::value, "");
    static_assert(equal<
        typename insert_keys<hset<k<0>>, seq<0>>::type,
        hset<k<0>>
    >::value, "");
    static_assert(equal<
        typename insert_keys<hset<k<0>>, seq<0, 0>>::type,
        hset<k<0>>
    >::value, "");
    static_assert(equal<
        typename insert_keys<hset<k<0>>, seq<1>>::type,
        hset<k<0>, k<1>>
    >::value, "");
    static_assert(equal<
        typename insert_keys<hset<k<0>>, seq<0, 1>>::type,
        hset<k<0>, k<1>>
    >::value, "");


    // insert_key
    static_assert(equal<
        typename insert_key<hset<>, k<0>>::type,
        hset<k<0>>
    >::value, "");
    static_assert(equal<
        typename insert_key<hset<k<0>>, k<0>>::type,
        hset<k<0>>
    >::value, "");
    static_assert(equal<
        typename insert_key<hset<k<0>>, k<1>>::type,
        hset<k<0>, k<1>>
    >::value, "");

    static_assert(equal<
        typename insert_key<hset<k<0>, k<1>>, k<0>>::type,
        hset<k<0>, k<1>>
    >::value, "");
    static_assert(equal<
        typename insert_key<hset<k<0>, k<1>>, k<1>>::type,
        hset<k<0>, k<1>>
    >::value, "");
    static_assert(equal<
        typename insert_key<hset<k<0>, k<1>>, k<2>>::type,
        hset<k<0>, k<1>, k<2>>
    >::value, "");


    // erase_keys
    static_assert(equal<
        typename erase_keys<hset<>, seq<>>::type,
        hset<>
    >::value, "");
    static_assert(equal<
        typename erase_keys<hset<>, seq<0>>::type,
        hset<>
    >::value, "");
    static_assert(equal<
        typename erase_keys<hset<>, seq<0, 1>>::type,
        hset<>
    >::value, "");

    static_assert(equal<
        typename erase_keys<hset<k<0>>, seq<>>::type,
        hset<k<0>>
    >::value, "");
    static_assert(equal<
        typename erase_keys<hset<k<0>>, seq<0>>::type,
        hset<>
    >::value, "");
    static_assert(equal<
        typename erase_keys<hset<k<0>>, seq<0, 0>>::type,
        hset<>
    >::value, "");
    static_assert(equal<
        typename erase_keys<hset<k<0>>, seq<1>>::type,
        hset<k<0>>
    >::value, "");

    static_assert(equal<
        typename erase_keys<hset<k<0>, k<1>>, seq<>>::type,
        hset<k<0>, k<1>>
    >::value, "");
    static_assert(equal<
        typename erase_keys<hset<k<0>, k<1>>, seq<0>>::type,
        hset<k<1>>
    >::value, "");
    static_assert(equal<
        typename erase_keys<hset<k<0>, k<1>>, seq<1>>::type,
        hset<k<0>>
    >::value, "");
    static_assert(equal<
        typename erase_keys<hset<k<0>, k<1>>, seq<0, 1>>::type,
        hset<>
    >::value, "");
    static_assert(equal<
        typename erase_keys<hset<k<0>, k<1>>, seq<2>>::type,
        hset<k<0>, k<1>>
    >::value, "");
    static_assert(equal<
        typename erase_keys<hset<k<0>, k<1>>, seq<0, 1, 0, 1>>::type,
        hset<>
    >::value, "");


    // erase_key
    static_assert(equal<
        typename erase_key<hset<>, k<0>>::type,
        hset<>
    >::value, "");

    static_assert(equal<
        typename erase_key<hset<k<0>>, k<0>>::type,
        hset<>
    >::value, "");
    static_assert(equal<
        typename erase_key<hset<k<0>>, k<1>>::type,
        hset<k<0>>
    >::value, "");

    static_assert(equal<
        typename erase_key<hset<k<0>, k<1>>, k<0>>::type,
        hset<k<1>>
    >::value, "");
    static_assert(equal<
        typename erase_key<hset<k<0>, k<1>>, k<1>>::type,
        hset<k<0>>
    >::value, "");
    static_assert(equal<
        typename erase_key<hset<k<0>, k<1>>, k<2>>::type,
        hset<k<0>, k<1>>
    >::value, "");
};

struct test_all
    : test_one<new_<hset<>>>,
      test_one<lambda<insert_keys<hset<>, _1>>>,
      test_one<lambda<foldl<_1, hset<>, quote<insert_key>>>>
{ };


int main() { }
