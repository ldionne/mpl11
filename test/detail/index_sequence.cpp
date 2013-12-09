/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::index_sequence`.
 */

#include <boost/mpl11/detail/index_sequence.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using namespace detail;

static_assert(is_same<
    make_index_sequence<0>::type,
    index_sequence<>
>::value, "");

static_assert(is_same<
    make_index_sequence<1>::type,
    index_sequence<0>
>::value, "");

static_assert(is_same<
    make_index_sequence<2>::type,
    index_sequence<0, 1>
>::value, "");

static_assert(is_same<
    make_index_sequence<3>::type,
    index_sequence<0, 1, 2>
>::value, "");

static_assert(is_same<
    make_index_sequence<4>::type,
    index_sequence<0, 1, 2, 3>
>::value, "");

static_assert(is_same<
    make_index_sequence<5>::type,
    index_sequence<0, 1, 2, 3, 4>
>::value, "");

static_assert(is_same<
    make_index_sequence<6>::type,
    index_sequence<0, 1, 2, 3, 4, 5>
>::value, "");


int main() { }
