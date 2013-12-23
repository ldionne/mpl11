/*!
 * @file
 * Contains unit tests for `boost::mpl11::transform`.
 */

#include <boost/mpl11/transform.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename ...T>
using seq = vector<T...>;

struct x; struct y; struct z;
struct f { template <typename ...> struct apply { struct type; }; };

/////////////////////////////////
// ForwardSequence
/////////////////////////////////
// head
template <typename ...T> struct head_of {
    template <typename Head> struct is {
        static_assert(is_same<
            head_t<transform<f, seq<T...>>>, apply_t<f, Head>
        >::value, "");
    };
};
struct test_head :
    head_of<x>::is<x>,
    head_of<x, y>::is<x>,
    head_of<x, y, z>::is<x>
{ };

// tail
template <typename ...T> struct tail_of {
    template <typename ...Tail> struct is {
        static_assert(equal<
            vector<apply_t<f, Tail>...>,
            tail_t<transform<f, seq<T...>>>
        >::value, "");
    };
};
struct test_tail :
    tail_of<x>::is<>,
    tail_of<x, y>::is<y>,
    tail_of<x, y, z>::is<y, z>
{ };

// is_empty
static_assert( is_empty<transform<f, seq<>>>::value, "");
static_assert(!is_empty<transform<f, seq<x>>>::value, "");
static_assert(!is_empty<transform<f, seq<x, y>>>::value, "");
static_assert(!is_empty<transform<f, seq<x, y, z>>>::value, "");


/////////////////////////////////
// FiniteSequence
/////////////////////////////////
// length
static_assert(length<transform<f, seq<>>>::value == 0, "");
static_assert(length<transform<f, seq<x>>>::value == 1, "");
static_assert(length<transform<f, seq<x, y>>>::value == 2, "");
static_assert(length<transform<f, seq<x, y, z>>>::value == 3, "");

// unpack
template <typename ...T>
struct test_unpack_one {
    static_assert(is_same<
        unpack_t<transform<f, seq<T...>>, into<vector>>,
        vector<apply_t<f, T>...>
    >::value, "");
};
struct test_unpack :
    test_unpack_one<>,
    test_unpack_one<x>,
    test_unpack_one<x, y>,
    test_unpack_one<x, y, z>
{ };


/////////////////////////////////
// BidirectionalSequence
/////////////////////////////////
// last
template <typename ...T> struct last_of {
    template <typename Last> struct is {
        static_assert(is_same<
            last_t<transform<f, seq<T...>>>, apply_t<f, Last>
        >::value, "");
    };
};
struct test_last :
    last_of<x>::is<x>,
    last_of<x, y>::is<y>,
    last_of<x, y, z>::is<z>
{ };

// init
template <typename ...T> struct init_of {
    template <typename ...Init> struct is {
        static_assert(equal<
            vector<apply_t<f, Init>...>,
            init_t<transform<f, seq<T...>>>
        >::value, "");
    };
};
struct test_init :
    init_of<x>::is<>,
    init_of<x, y>::is<x>,
    init_of<x, y, z>::is<x, y>
{ };


/////////////////////////////////
// RandomAccessSequence
/////////////////////////////////
// at
template <unsigned long i, typename ...T> struct at_index {
    template <typename X> struct is {
        static_assert(is_same<
            at_c_t<transform<f, seq<T...>>, i>, apply_t<f, X>
        >::value, "");
    };
};
struct test_at :
    at_index<0, x>::is<x>,

    at_index<0, x, y>::is<x>,
    at_index<1, x, y>::is<y>,

    at_index<0, x, y, z>::is<x>,
    at_index<1, x, y, z>::is<y>,
    at_index<2, x, y, z>::is<z>
{ };

// slice
template <unsigned long Start, unsigned long Stop, typename ...T>
struct slice_at {
    template <typename ...Slice> struct is {
        static_assert(equal<
            vector<apply_t<f, Slice>...>,
            slice_c_t<transform<f, seq<T...>>, Start, Stop>
        >::value, "");
    };
};
struct test_slice :
    slice_at<0, 0>::is<>,

    slice_at<0, 0, x>::is<>,
    slice_at<0, 1, x>::is<x>,
    slice_at<1, 1, x>::is<>,

    slice_at<0, 0, x, y>::is<>,
    slice_at<0, 1, x, y>::is<x>,
    slice_at<0, 2, x, y>::is<x, y>,
    slice_at<1, 1, x, y>::is<>,
    slice_at<1, 2, x, y>::is<y>,
    slice_at<2, 2, x, y>::is<>
{ };


int main() { }
