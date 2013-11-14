/*!
 * @file
 * Contains unit tests for `boost::mpl11::ForwardIterator`.
 */

#include <boost/mpl11/forward_iterator.hpp>

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/distance.hpp>

#include "minimal_requirements.hpp"
#include "positional_iterator.hpp"


using namespace boost::mpl11;
using detail::is_same;

template <unsigned long i>
using it = test::wrapper<
    test::minimal_requirements<ForwardIterator>,
    test::positional_iterator<i>
>;

// advance
static_assert(is_same<advance_c<it<0>, 0>::type, it<0 + 0>>::value, "");
static_assert(is_same<advance_c<it<0>, 1>::type, it<0 + 1>>::value, "");
static_assert(is_same<advance_c<it<0>, 2>::type, it<0 + 2>>::value, "");

static_assert(is_same<advance_c<it<1>, 0>::type, it<1 + 0>>::value, "");
static_assert(is_same<advance_c<it<1>, 1>::type, it<1 + 1>>::value, "");
static_assert(is_same<advance_c<it<1>, 2>::type, it<1 + 2>>::value, "");

static_assert(is_same<advance_c<it<2>, 0>::type, it<2 + 0>>::value, "");
static_assert(is_same<advance_c<it<2>, 1>::type, it<2 + 1>>::value, "");
static_assert(is_same<advance_c<it<2>, 2>::type, it<2 + 2>>::value, "");
static_assert(is_same<advance_c<it<2>, 3>::type, it<2 + 3>>::value, "");

static_assert(is_same<advance_c<it<0>, 100>::type, it<0 + 100>>::value, "");


// distance
static_assert(distance<it<0>, it<0>>::value == 0 - 0, "");
static_assert(distance<it<0>, it<1>>::value == 1 - 0, "");
static_assert(distance<it<0>, it<2>>::value == 2 - 0, "");

static_assert(distance<it<1>, it<1>>::value == 1 - 1, "");
static_assert(distance<it<1>, it<2>>::value == 2 - 1, "");
static_assert(distance<it<1>, it<3>>::value == 3 - 1, "");

static_assert(distance<it<2>, it<2>>::value == 2 - 2, "");
static_assert(distance<it<2>, it<3>>::value == 3 - 2, "");
static_assert(distance<it<2>, it<4>>::value == 4 - 2, "");

static_assert(distance<it<0>, it<100>>::value == 100 - 0, "");


int main() { }
