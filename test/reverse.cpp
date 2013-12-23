/*!
 * @file
 * Contains unit tests for `boost::mpl11::reverse`.
 */

#include <boost/mpl11/reverse.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <int ...i>
using seq = vector_c<int, i...>;

struct x0; struct x1; struct x2; struct x3; struct x4; struct x5; struct x6;

/////////////////////////////////
// ForwardSequence
/////////////////////////////////
// head
template <int ...I> struct head_of {
    template <int Head> struct is
    { static_assert(head_t<reverse<seq<I...>>>::value == Head, ""); };
};
struct test_head :
    head_of<0>::is<0>,
    head_of<0, 1>::is<1>,
    head_of<0, 1, 2>::is<2>,
    head_of<0, 1, 2, 3>::is<3>
{ };

// tail
template <int ...I> struct tail_of {
    template <int ...Tail> struct is {
        static_assert(equal<
            vector_c<int, Tail...>, tail_t<reverse<seq<I...>>>
        >::value, "");
    };
};
struct test_tail :
    tail_of<0>::is<>,
    tail_of<0, 1>::is<0>,
    tail_of<0, 1, 2>::is<1, 0>,
    tail_of<0, 1, 2, 3>::is<2, 1, 0>,
    tail_of<0, 1, 2, 3, 4>::is<3, 2, 1, 0>
{ };

// is_empty
static_assert( is_empty<reverse<seq<>>>::value, "");
static_assert(!is_empty<reverse<seq<0>>>::value, "");
static_assert(!is_empty<reverse<seq<0, 1>>>::value, "");
static_assert(!is_empty<reverse<seq<0, 1, 2>>>::value, "");


/////////////////////////////////
// FiniteSequence
/////////////////////////////////
// length
static_assert(length<reverse<seq<>>>::value == 0, "");
static_assert(length<reverse<seq<0>>>::value == 1, "");
static_assert(length<reverse<seq<0, 1>>>::value == 2, "");
static_assert(length<reverse<seq<0, 1, 2>>>::value == 3, "");

// unpack
template <int ...I> struct unpacking {
    template <int ...Unpacked> struct is {
        static_assert(is_same<
            unpack_t<reverse<seq<I...>>, into<vector>>,
            vector_c<int, Unpacked...>
        >::value, "");
    };
};
struct test_unpack :
    unpacking<>::is<>,
    unpacking<0>::is<0>,
    unpacking<0, 1>::is<1, 0>,
    unpacking<0, 1, 2>::is<2, 1, 0>,
    unpacking<0, 1, 2, 3>::is<3, 2, 1, 0>,
    unpacking<0, 1, 2, 3, 4>::is<4, 3, 2, 1, 0>
{ };


/////////////////////////////////
// BidirectionalSequence
/////////////////////////////////
// last
template <int ...I> struct last_of {
    template <int Last> struct is
    { static_assert(last_t<reverse<seq<I...>>>::value == Last, ""); };
};
struct test_last :
    last_of<0>::is<0>,
    last_of<0, 1>::is<0>,
    last_of<0, 1, 2>::is<0>,
    last_of<0, 1, 2, 3>::is<0>
{ };

// init
template <int ...I> struct init_of {
    template <int ...Init> struct is {
        static_assert(equal<
            vector_c<int, Init...>, init_t<reverse<seq<I...>>>
        >::value, "");
    };
};
struct test_init :
    init_of<0>::is<>,
    init_of<0, 1>::is<1>,
    init_of<0, 1, 2>::is<2, 1>,
    init_of<0, 1, 2, 3>::is<3, 2, 1>,
    init_of<0, 1, 2, 3, 4>::is<4, 3, 2, 1>
{ };


/////////////////////////////////
// RandomAccessSequence
/////////////////////////////////
// at
template <unsigned long Index, int ...I> struct at_index {
    template <int X> struct is
    { static_assert(at_c_t<reverse<seq<I...>>, Index>::value == X, ""); };
};
struct test_at :
    at_index<0ul, 0>::is<0>,

    at_index<0ul, 0, 1>::is<1>,
    at_index<1ul, 0, 1>::is<0>,

    at_index<0ul, 0, 1, 2>::is<2>,
    at_index<1ul, 0, 1, 2>::is<1>,
    at_index<2ul, 0, 1, 2>::is<0>,

    at_index<0ul, 0, 1, 2, 3>::is<3>,
    at_index<1ul, 0, 1, 2, 3>::is<2>,
    at_index<2ul, 0, 1, 2, 3>::is<1>,
    at_index<3ul, 0, 1, 2, 3>::is<0>
{ };

// slice
template <unsigned long Start, unsigned long Stop, int ...I> struct slice_at {
    template <int ...Slice> struct is {
        static_assert(equal<
            vector_c<int, Slice...>,
            slice_c_t<reverse<seq<I...>>, Start, Stop>
        >::value, "");
    };
};
struct test_slice :
    slice_at<0ul, 0ul>::is<>,

    slice_at<0ul, 0ul, 0>::is<>,
    slice_at<0ul, 1ul, 0>::is<0>,
    slice_at<1ul, 1ul, 0>::is<>,

    slice_at<0ul, 0ul, 0, 1>::is<>,
    slice_at<0ul, 1ul, 0, 1>::is<1>,
    slice_at<0ul, 2ul, 0, 1>::is<1, 0>,
    slice_at<1ul, 1ul, 0, 1>::is<>,
    slice_at<1ul, 2ul, 0, 1>::is<0>,
    slice_at<2ul, 2ul, 0, 1>::is<>,

    slice_at<0ul, 0ul, 0, 1, 2>::is<>,
    slice_at<0ul, 1ul, 0, 1, 2>::is<2>,
    slice_at<0ul, 2ul, 0, 1, 2>::is<2, 1>,
    slice_at<0ul, 3ul, 0, 1, 2>::is<2, 1, 0>,
    slice_at<1ul, 1ul, 0, 1, 2>::is<>,
    slice_at<1ul, 2ul, 0, 1, 2>::is<1>,
    slice_at<1ul, 3ul, 0, 1, 2>::is<1, 0>,
    slice_at<2ul, 2ul, 0, 1, 2>::is<>,
    slice_at<2ul, 3ul, 0, 1, 2>::is<0>,
    slice_at<3ul, 3ul, 0, 1, 2>::is<>,

    slice_at<3ul, 7ul, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9>::is<6, 5, 4, 3>
{ };


int main() { }
