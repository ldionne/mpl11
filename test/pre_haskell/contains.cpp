/*!
 * @file
 * Contains unit tests for `boost::mpl11::contains`.
 */

#include <boost/mpl11/contains.hpp>

#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;

template <typename ...T>
using sequence = test::wrapper<
    test::minimal_requirements<Sequence>, vector<T...>
>;

static_assert(!contains<sequence<>, t<0>>::value, "");

static_assert( contains<sequence<t<0>>, t<0>>::value, "");
static_assert(!contains<sequence<t<0>>, t<1>>::value, "");

static_assert( contains<sequence<t<0>, t<1>>, t<0>>::value, "");
static_assert( contains<sequence<t<0>, t<1>>, t<1>>::value, "");
static_assert(!contains<sequence<t<0>, t<1>>, t<2>>::value, "");

static_assert( contains<sequence<t<0>, t<1>, t<2>>, t<0>>::value, "");
static_assert( contains<sequence<t<0>, t<1>, t<2>>, t<1>>::value, "");
static_assert( contains<sequence<t<0>, t<1>, t<2>>, t<2>>::value, "");
static_assert(!contains<sequence<t<0>, t<1>, t<2>>, t<3>>::value, "");

static_assert(contains<sequence<t<0>, t<0>, t<2>>, t<0>>::value, "");
static_assert(contains<sequence<t<1>, t<1>, t<2>>, t<1>>::value, "");
static_assert(contains<sequence<t<0>, t<2>, t<2>>, t<2>>::value, "");


int main() { }
