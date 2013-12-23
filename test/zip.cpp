/*!
 * @file
 * Contains unit tests for `boost::mpl11::zip`.
 */

#include <boost/mpl11/zip.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename ...T>
using seq = vector<T...>;

struct w0; struct w1; struct w2; struct w3; struct w4;
struct x0; struct x1; struct x2; struct x3; struct x4;
struct y0; struct y1; struct y2; struct y3; struct y4;
struct z0; struct z1; struct z2; struct z3; struct z4;

/////////////////////////////////
// ForwardSequence
/////////////////////////////////
// head
template <typename ...Sn> struct head_of {
    template <typename ...x> struct is
    { static_assert(is_same<head_t<zip<Sn...>>, vector<x...>>::value, ""); };
};
struct test_head :
    head_of<seq<w0>, seq<x0>>::is<w0, x0>,
    head_of<seq<w0>, seq<x0>, seq<y0>>::is<w0, x0, y0>,
    head_of<seq<w0, w1>, seq<x0>, seq<y0>>::is<w0, x0, y0>
{ };

// tail
template <typename ...Sn> struct tail_of {
    template <typename ...Sx> struct is
    { static_assert(is_same<tail_t<zip<Sn...>>, zip<Sx...>>::value, ""); };
};
struct test_tail :
    tail_of<seq<w0>, seq<x0>>::is<seq<>, seq<>>,
    tail_of<seq<w0>, seq<x0>, seq<y0>>::is<seq<>, seq<>, seq<>>,
    tail_of<seq<w0, w1>, seq<x0>, seq<y0>>::is<seq<w1>, seq<>, seq<>>
{ };

// is_empty
static_assert( is_empty<zip<seq<>, seq<>>>::value, "");
static_assert( is_empty<zip<seq<w0>, seq<>>>::value, "");
static_assert( is_empty<zip<seq<>, seq<x0>>>::value, "");
static_assert(!is_empty<zip<seq<w0>, seq<x0>>>::value, "");


/////////////////////////////////
// FiniteSequence
/////////////////////////////////
// length
static_assert(length<zip<seq<>, seq<>>>::value == 0, "");
static_assert(length<zip<seq<w0>, seq<>>>::value == 0, "");
static_assert(length<zip<seq<>, seq<x0>>>::value == 0, "");
static_assert(length<zip<seq<w0>, seq<x0>>>::value == 1, "");

// unpack
template <typename ...Sn> struct unpacking {
    template <typename ...Sx> struct is {
        static_assert(is_same<
            unpack_t<zip<Sn...>, into<vector>>,
            vector<Sx...>
        >::value, "");
    };
};
struct test_unpack :
    unpacking<seq<>, seq<>>::is<>,
    unpacking<seq<w0>, seq<>>::is<>,
    unpacking<seq<>, seq<x0>>::is<>,
    unpacking<seq<w0>, seq<x0>>::is<vector<w0, x0>>,
    unpacking<seq<w0, w1>, seq<x0, x1>>::is<vector<w0, x0>, vector<w1, x1>>,
    unpacking<
        seq<w0, w1, w2, w3>,
        seq<x0, x1, x2, x3, x4>,
        seq<y0, y1, y2>,
        seq<z0, z1, z2, z3, z4>
    >::is<
        vector<w0, x0, y0, z0>,
        vector<w1, x1, y1, z1>,
        vector<w2, x2, y2, z2>
    >
{ };

#if 0
/////////////////////////////////
// BidirectionalSequence
/////////////////////////////////
// last
template <typename ...Sn> struct last_of {
    template <typename ...x> struct is
    { static_assert(is_same<last_t<zip<Sn...>>, vector<x...>>::value, ""); };
};
struct test_last :
    last_of<seq<w0>, seq<x0>>::is<w0, x0>,
    last_of<seq<w0, w1>, seq<x0>>::is<w0, x0>,
    last_of<seq<w0>, seq<x0, x1>>::is<w0, x0>,
    last_of<seq<w0, w1>, seq<x0, x1>>::is<w1, x1>
{ };

// init
template <typename ...Sn> struct init_of {
    template <typename ...Sx> struct is
    { static_assert(is_same<init_t<zip<Sn...>>, zip<Sx...>>::value, ""); };
};
struct test_init :
    init_of<seq<w0>, seq<x0>>::is<seq<>, seq<>>,
    init_of<seq<w0>, seq<x0>, seq<y0>>::is<seq<>, seq<>, seq<>>,
    init_of<seq<w0, w1>, seq<x0>, seq<y0>>::is<seq<w0>, seq<>, seq<>>
{ };
#endif

/////////////////////////////////
// RandomAccessSequence
/////////////////////////////////
// at
template <unsigned long i, typename ...Sn> struct at_index {
    template <typename ...x> struct is
    { static_assert(is_same<at_c_t<zip<Sn...>, i>, vector<x...>>::value, ""); };
};
struct test_at :
    at_index<0, seq<w0>, seq<x0>>::is<w0, x0>,
    at_index<0, seq<w0, w1>, seq<x0, x1>>::is<w0, x0>,
    at_index<1, seq<w0, w1>, seq<x0, x1>>::is<w1, x1>
{ };

// slice
template <unsigned long Start, unsigned long Stop, typename ...Sn>
struct slice_at {
    template <typename ...Sx> struct is {
        static_assert(is_same<
            slice_c_t<zip<Sn...>, Start, Stop>,
            zip<Sx...>
        >::value, "");
    };
};
struct test_slice :
    slice_at<0, 0, seq<>, seq<>>::is<seq<>, seq<>>,
    slice_at<0, 0, seq<w0>, seq<x0>>::is<seq<>, seq<>>,
    slice_at<0, 1, seq<w0>, seq<x0>>::is<seq<w0>, seq<x0>>
{ };


int main() { }
