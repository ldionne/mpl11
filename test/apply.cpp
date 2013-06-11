/*!
 * @file
 * This file contains unit tests for `boost::mpl11::apply`.
 */

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/pack.hpp>
#include <boost/mpl11/placeholders.hpp>
#include <boost/mpl11/quote.hpp>

#include <type_traits>


using namespace boost::mpl11;

static_assert(std::is_same<
    int,
    apply<quote<identity>, int>::type
>::value, "");

// apply with placeholder expressions
static_assert(std::is_same<
    apply<identity<_1>, int>::type,
    int
>::value, "");

static_assert(std::is_same<
    apply<pack<_1, _2, _all>, int, char, float>::type,
    pack<int, char, int, char, float>
>::value, "");

// apply with a non-template apply member.
template <typename T>
struct weird_meta_identity {
    struct apply { using type = T; };
};
static_assert(std::is_same<
    apply<weird_meta_identity<int>>::type,
    int
>::value, "");
