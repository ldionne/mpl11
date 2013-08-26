/*!
 * @file
 * This file contains unit tests for `boost::mpl11::kwargs`.
 */

#include <boost/mpl11/functional/kwargs.hpp>
#include <boost/mpl11/container/map.hpp>
#include <boost/mpl11/functional/apply.hpp>
#include <boost/mpl11/functional/named_argument.hpp>
#include <boost/mpl11/is_same.hpp>


using namespace boost::mpl11;

template <typename ...> struct named;
template <typename ...> struct positional;

template <typename Positional, typename Named>
struct test;

template <typename ...Positional, typename ...Named>
struct test<positional<Positional...>, named<Named...>>
    : is_same<
        typename apply<map<kwargs>, Positional..., Named...>::type,
        map<Named...>
    >
{ };

static_assert(test<positional<>, named<>>::value, "");

static_assert(test<
    positional<>,
    named<
        named_argument<struct tag, int>
    >
>::value, "");

static_assert(test<
    positional<>,
    named<
        named_argument<struct int_tag, int>,
        named_argument<struct float_tag, float>
    >
>::value, "");


int main() { }
