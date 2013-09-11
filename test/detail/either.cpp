/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::either`.
 */

#include <boost/mpl11/detail/either.hpp>

#include <boost/mpl11/operator/equal_to.hpp>


using namespace boost::mpl11;
using detail::either;


template <int> struct metafunction { struct type; };
struct incomplete;
struct not_a_metafunction { };
using non_class = int;

// Picks the left metafunction whenever it is valid.
static_assert(equal_to<
    either<metafunction<0>, metafunction<1>>::type,
    metafunction<0>::type
>::type::value, "");

// Use short-circuit evaluation: don't evaluate Right if Left is valid.
static_assert(equal_to<
    either<metafunction<0>, incomplete>::type,
    metafunction<0>::type
>::type::value, "");

// Picks the right metafunction when the left one does not have a nested type.
static_assert(equal_to<
    either<incomplete, metafunction<0>>::type,
    metafunction<0>::type
>::type::value, "");

static_assert(equal_to<
    either<not_a_metafunction, metafunction<0>>::type,
    metafunction<0>::type
>::type::value, "");

static_assert(equal_to<
    either<non_class, metafunction<0>>::type,
    metafunction<0>::type
>::type::value, "");

// Works with more than two types.
static_assert(equal_to<
    either<metafunction<0>, metafunction<1>, metafunction<2>>::type,
    metafunction<0>::type
>::type::value, "");

static_assert(equal_to<
    either<incomplete, non_class, metafunction<0>>::type,
    metafunction<0>::type
>::type::value, "");

static_assert(equal_to<
    either<incomplete, non_class, metafunction<0>, not_a_metafunction>::type,
    metafunction<0>::type
>::type::value, "");


int main() { }
