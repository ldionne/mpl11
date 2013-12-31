/*!
 * @file
 * Contains unit tests for `boost::mpl11::take`.
 */

#include <boost/mpl11/take.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <int ...i>
using seq = vector_c<int, i...>;

/////////////////////////////////
// ForwardSequence
/////////////////////////////////
// head
template <unsigned long N, int ...I> struct head_of {
    template <int Head> struct is
    { static_assert(head_t<take_c<N, seq<I...>>>::value == Head, ""); };
};
struct test_head :
    head_of<1ul, 0>::is<0>,
    head_of<1ul, 0, 1>::is<0>,
    head_of<1ul, 0, 1, 2>::is<0>,

    head_of<2ul, 0>::is<0>,
    head_of<2ul, 0, 1>::is<0>,
    head_of<2ul, 0, 1, 2>::is<0>,

    head_of<3ul, 0>::is<0>,
    head_of<3ul, 0, 1>::is<0>,
    head_of<3ul, 0, 1, 2>::is<0>
{ };

// tail
template <unsigned long N, int ...I> struct tail_of {
    template <int ...Tail> struct is {
        static_assert(equal<
            vector_c<int, Tail...>,
            tail_t<take_c<N, seq<I...>>>
        >::value, "");
    };
};
struct test_tail :
    tail_of<1ul, 1>::is<>,
    tail_of<1ul, 1, 2>::is<>,
    tail_of<1ul, 1, 2, 3>::is<>,

    tail_of<2ul, 1>::is<>,
    tail_of<2ul, 1, 2>::is<2>,
    tail_of<2ul, 1, 2, 3>::is<2>,
    tail_of<2ul, 1, 2, 3, 4>::is<2>,

    tail_of<3ul, 1>::is<>,
    tail_of<3ul, 1, 2>::is<2>,
    tail_of<3ul, 1, 2, 3>::is<2, 3>,
    tail_of<3ul, 1, 2, 3, 4>::is<2, 3>,
    tail_of<3ul, 1, 2, 3, 4, 5>::is<2, 3>
{ };

// is_empty
static_assert( is_empty<take_c<0, seq<>>>::value, "");
static_assert( is_empty<take_c<0, seq<0>>>::value, "");
static_assert( is_empty<take_c<0, seq<0, 1>>>::value, "");

static_assert( is_empty<take_c<1, seq<>>>::value, "");
static_assert(!is_empty<take_c<1, seq<0>>>::value, "");
static_assert(!is_empty<take_c<1, seq<0, 1>>>::value, "");

static_assert( is_empty<take_c<2, seq<>>>::value, "");
static_assert(!is_empty<take_c<2, seq<0>>>::value, "");
static_assert(!is_empty<take_c<2, seq<0, 2>>>::value, "");


/////////////////////////////////
// FiniteSequence
/////////////////////////////////
// length
static_assert(length<take_c<0, seq<>>>::value == 0, "");
static_assert(length<take_c<0, seq<0>>>::value == 0, "");
static_assert(length<take_c<0, seq<0, 1>>>::value == 0, "");

static_assert(length<take_c<1, seq<>>>::value == 0, "");
static_assert(length<take_c<1, seq<0>>>::value == 1, "");
static_assert(length<take_c<1, seq<0, 1>>>::value == 1, "");

static_assert(length<take_c<2, seq<>>>::value == 0, "");
static_assert(length<take_c<2, seq<0>>>::value == 1, "");
static_assert(length<take_c<2, seq<0, 1>>>::value == 2, "");


// unpack
template <unsigned long N, int ...I> struct unpacking {
    template <int ...Unpacked> struct is {
        static_assert(is_same<
            unpack_t<take_c<N, seq<I...>>, into<vector>>,
            vector_c<int, Unpacked...>
        >::value, "");
    };
};
struct test_unpack :
    unpacking<0ul>::is<>,
    unpacking<0ul, 0>::is<>,
    unpacking<0ul, 0, 1>::is<>,
    unpacking<0ul, 0, 1, 2>::is<>,

    unpacking<1ul>::is<>,
    unpacking<1ul, 0>::is<0>,
    unpacking<1ul, 0, 1>::is<0>,
    unpacking<1ul, 0, 1, 2>::is<0>,

    unpacking<2ul>::is<>,
    unpacking<2ul, 0>::is<0>,
    unpacking<2ul, 0, 1>::is<0, 1>,
    unpacking<2ul, 0, 1, 2>::is<0, 1>
{ };


/////////////////////////////////
// BidirectionalSequence
/////////////////////////////////
// last
template <unsigned long N, int ...I> struct last_of {
    template <int Last> struct is
    { static_assert(last_t<take_c<N, seq<I...>>>::value == Last, ""); };
};
struct test_last :
    last_of<1ul, 1>::is<1>,
    last_of<1ul, 1, 2>::is<1>,
    last_of<1ul, 1, 2, 3>::is<1>,

    last_of<2ul, 1>::is<1>,
    last_of<2ul, 1, 2>::is<2>,
    last_of<2ul, 1, 2, 3>::is<2>
{ };

// init
template <unsigned long N, int ...I> struct init_of {
    template <int ...Init> struct is {
        static_assert(equal<
            vector_c<int, Init...>,
            init_t<take_c<N, seq<I...>>>
        >::value, "");
    };
};
struct test_init :
    init_of<1ul, 0>::is<>,
    init_of<1ul, 0, 1>::is<>,
    init_of<1ul, 0, 1, 2>::is<>,

    init_of<2ul, 0>::is<>,
    init_of<2ul, 0, 1>::is<0>,
    init_of<2ul, 0, 1, 2>::is<0>,

    init_of<3ul, 0>::is<>,
    init_of<3ul, 0, 1>::is<0>,
    init_of<3ul, 0, 1, 2>::is<0, 1>,
    init_of<3ul, 0, 1, 2, 3>::is<0, 1>
{ };


/////////////////////////////////
// RandomAccessSequence
/////////////////////////////////
// at
template <unsigned long Index, int ...I> struct at_index {
    template <unsigned long N> struct taking {
        template <int Value> struct is {
            static_assert(
                at_c_t<take_c<N, seq<I...>>, Index>::value == Value
            , "");
        };
    };
};
struct test_at :
    at_index<0ul, 0>::taking<1>::is<0>,
    at_index<0ul, 0>::taking<2>::is<0>,
    at_index<0ul, 0>::taking<3>::is<0>,

    at_index<0ul, 0, 1>::taking<1>::is<0>,
    at_index<0ul, 0, 1>::taking<2>::is<0>,
    at_index<0ul, 0, 1>::taking<3>::is<0>,

    at_index<1ul, 0, 1>::taking<2>::is<1>,
    at_index<1ul, 0, 1>::taking<3>::is<1>
{ };

// slice
template <unsigned long Start, unsigned long Stop, int ...I> struct slice_at {
    template <int N> struct taking {
        template <int ...Sliced> struct is {
            static_assert(equal<
                vector_c<int, Sliced...>,
                slice_c_t<take_c<N, seq<I...>>, Start, Stop>
            >::value, "");
        };
    };
};
struct test_slice :
    slice_at<0ul, 0ul>::taking<0>::is<>,
    slice_at<0ul, 0ul>::taking<1>::is<>,
    slice_at<0ul, 0ul>::taking<2>::is<>,

    slice_at<0ul, 0ul, 0>::taking<0>::is<>,
    slice_at<0ul, 0ul, 0>::taking<1>::is<>,
    slice_at<0ul, 0ul, 0>::taking<2>::is<>,

    slice_at<0ul, 1ul, 0>::taking<1>::is<0>,
    slice_at<0ul, 1ul, 0>::taking<2>::is<0>,

    slice_at<0ul, 2ul, 0, 1>::taking<2>::is<0, 1>
{ };


int main() { }
