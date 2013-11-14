/*!
 * @file
 * Contains unit tests for `boost::mpl11::Sequence`.
 */

#include <boost/mpl11/sequence.hpp>

#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/size.hpp>
#include <boost/mpl11/vector.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;

template <int ...i>
using sequence = test::wrapper<
    test::minimal_requirements<Sequence>, vector_c<int, i...>
>;

// size
static_assert(size<sequence<>>::value == 0, "");
static_assert(size<sequence<0>>::value == 1, "");
static_assert(size<sequence<0, 1>>::value == 2, "");
static_assert(size<sequence<0, 1, 2>>::value == 3, "");
static_assert(size<sequence<0, 1, 2, 3>>::value == 4, "");
static_assert(size<sequence<0, 1, 2, 3, 4>>::value == 5, "");

// is_empty
static_assert( is_empty<sequence<>>::value, "");
static_assert(!is_empty<sequence<0>>::value, "");
static_assert(!is_empty<sequence<0, 1>>::value, "");
static_assert(!is_empty<sequence<0, 1, 2>>::value, "");


int main() { }
