/*!
 * @file
 * Contains unit tests for `boost::mpl11::repeat`.
 */

#include <boost/mpl11/repeat.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;
struct X;

/////////////////////////////////
// ForwardSequence
/////////////////////////////////
// head
static_assert(is_same<head_t<repeat<X>>, X>::value, "");

// tail
static_assert(is_same<tail_t<repeat<X>>, repeat<X>>::value, "");

// is_empty
static_assert(!is_empty<repeat<X>>::value, "");


/////////////////////////////////
// BidirectionalSequence
/////////////////////////////////
// last
static_assert(is_same<last_t<repeat<X>>, X>::value, "");

// init
static_assert(is_same<init_t<repeat<X>>, repeat<X>>::value, "");


/////////////////////////////////
// RandomAccessSequence
/////////////////////////////////
// at
static_assert(is_same<at_c_t<repeat<X>, 0>, X>::value, "");
static_assert(is_same<at_c_t<repeat<X>, 1>, X>::value, "");
static_assert(is_same<at_c_t<repeat<X>, 2>, X>::value, "");

// slice
template <unsigned long Start, unsigned long Stop> struct slice_at {
    template <typename ...T> struct is {
        static_assert(equal<
            vector<T...>,
            slice_c_t<repeat<X>, Start, Stop>
        >::value, "");
    };
};
struct test_slice :
    slice_at<0, 0>::is<>,
    slice_at<0, 1>::is<X>,
    slice_at<0, 2>::is<X, X>,
    slice_at<0, 3>::is<X, X, X>,
    slice_at<1, 1>::is<>,
    slice_at<1, 2>::is<X>,
    slice_at<1, 3>::is<X, X>,
    slice_at<2, 2>::is<>,
    slice_at<2, 3>::is<X>,
    slice_at<3, 3>::is<>
{ };


int main() { }
