/*!
 * @file
 * Contains unit tests for `boost::mpl11::BidirectionalIterator`.
 */

#include <boost/mpl11/bidirectional_iterator.hpp>

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/detail/is_same.hpp>

#include "minimal_requirements.hpp"
#include "positional_iterator.hpp"


using namespace boost::mpl11;
using detail::is_same;

template <long long i>
using it = test::wrapper<
    test::minimal_requirements<BidirectionalIterator>,
    test::positional_iterator<i>
>;

// advance (negative)
static_assert(is_same<advance_c<it<-2>, -2>::type, it<-2 -2>>::value, "");
static_assert(is_same<advance_c<it<-2>, -1>::type, it<-2 -1>>::value, "");

static_assert(is_same<advance_c<it<-1>, -2>::type, it<-1 - 2>>::value, "");
static_assert(is_same<advance_c<it<-1>, -1>::type, it<-1 - 1>>::value, "");

static_assert(is_same<advance_c<it<0>, -2>::type, it<0 - 2>>::value, "");
static_assert(is_same<advance_c<it<0>, -1>::type, it<0 - 1>>::value, "");

static_assert(is_same<advance_c<it<1>, -2>::type, it<1 - 2>>::value, "");
static_assert(is_same<advance_c<it<1>, -1>::type, it<1 - 1>>::value, "");

static_assert(is_same<advance_c<it<2>, -2>::type, it<2 - 2>>::value, "");
static_assert(is_same<advance_c<it<2>, -1>::type, it<2 - 1>>::value, "");


// advance (positive or zero)
static_assert(is_same<advance_c<it<0>, 0>::type, it<0 + 0>>::value, "");
static_assert(is_same<advance_c<it<0>, 1>::type, it<0 + 1>>::value, "");
static_assert(is_same<advance_c<it<0>, 2>::type, it<0 + 2>>::value, "");

static_assert(is_same<advance_c<it<1>, 0>::type, it<1 + 0>>::value, "");
static_assert(is_same<advance_c<it<1>, 1>::type, it<1 + 1>>::value, "");
static_assert(is_same<advance_c<it<1>, 2>::type, it<1 + 2>>::value, "");

static_assert(is_same<advance_c<it<2>, 0>::type, it<2 + 0>>::value, "");
static_assert(is_same<advance_c<it<2>, 1>::type, it<2 + 1>>::value, "");
static_assert(is_same<advance_c<it<2>, 2>::type, it<2 + 2>>::value, "");


int main() { }
