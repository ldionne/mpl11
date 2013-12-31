/*!
 * @file
 * Contains unit tests for `boost::mpl11::join`.
 */

#include <boost/mpl11/join.hpp>

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
template <typename ...Sn> struct head_of {
    template <int Head> struct is
    { static_assert(head_t<join<Sn...>>::value == Head, ""); };
};
struct test_head :
    head_of<seq<0>, seq<>>::is<0>,
    head_of<seq<>, seq<1>>::is<1>,
    head_of<seq<0>, seq<1>>::is<0>,

    head_of<seq<0>, seq<>, seq<>>::is<0>,
    head_of<seq<>, seq<1>, seq<>>::is<1>,
    head_of<seq<>, seq<>, seq<2>>::is<2>,
    head_of<seq<0>, seq<1>, seq<2>>::is<0>
{ };

// tail
template <typename ...Sn> struct tail_of {
    template <int ...Tail> struct is {
        static_assert(equal<
            vector_c<int, Tail...>, tail_t<join<Sn...>>
        >::value, "");
    };
};
struct test_tail :
    tail_of<seq<0>, seq<>>::is<>,
    tail_of<seq<>, seq<1>>::is<>,
    tail_of<seq<0>, seq<1>>::is<1>,

    tail_of<seq<>, seq<>, seq<2>>::is<>,
    tail_of<seq<>, seq<1>, seq<>>::is<>,
    tail_of<seq<>, seq<1>, seq<2>>::is<2>,
    tail_of<seq<0>, seq<>, seq<>>::is<>,
    tail_of<seq<0>, seq<>, seq<2>>::is<2>,
    tail_of<seq<0>, seq<1>, seq<>>::is<1>,
    tail_of<seq<0>, seq<1>, seq<2>>::is<1, 2>
{ };

// is_empty
static_assert( is_empty<join<seq<>, seq<>>>::value, "");
static_assert(!is_empty<join<seq<0>, seq<>>>::value, "");
static_assert(!is_empty<join<seq<>, seq<1>>>::value, "");
static_assert(!is_empty<join<seq<0>, seq<1>>>::value, "");

static_assert( is_empty<join<seq<>, seq<>, seq<>>>::value, "");
static_assert(!is_empty<join<seq<0>, seq<>, seq<>>>::value, "");
static_assert(!is_empty<join<seq<>, seq<1>, seq<>>>::value, "");
static_assert(!is_empty<join<seq<>, seq<>, seq<2>>>::value, "");


/////////////////////////////////
// FiniteSequence
/////////////////////////////////
// length
static_assert(length<join<seq<>, seq<>>>::value == 0, "");
static_assert(length<join<seq<0>, seq<>>>::value == 1, "");
static_assert(length<join<seq<>, seq<1>>>::value == 1, "");
static_assert(length<join<seq<0>, seq<1>>>::value == 2, "");

static_assert(length<join<seq<>, seq<>, seq<>>>::value == 0, "");
static_assert(length<join<seq<0>, seq<>, seq<>>>::value == 1, "");
static_assert(length<join<seq<>, seq<1>, seq<>>>::value == 1, "");
static_assert(length<join<seq<>, seq<>, seq<2>>>::value == 1, "");
static_assert(length<join<seq<0>, seq<>, seq<2>>>::value == 2, "");
static_assert(length<join<seq<0>, seq<1>, seq<2>>>::value == 3, "");

// unpack
template <typename ...Sn> struct unpacking {
    template <int ...Unpacked> struct is {
        static_assert(is_same<
            vector_c<int, Unpacked...>,
            unpack_t<join<Sn...>, into<vector>>
        >::value, "");
    };
};
struct test_unpack :
    unpacking<seq<>, seq<>>::is<>,
    unpacking<seq<0>, seq<>>::is<0>,
    unpacking<seq<>, seq<1>>::is<1>,
    unpacking<seq<0>, seq<1>>::is<0, 1>,

    unpacking<seq<>, seq<>, seq<>>::is<>,
    unpacking<seq<>, seq<>, seq<2>>::is<2>,
    unpacking<seq<>, seq<1>, seq<>>::is<1>,
    unpacking<seq<>, seq<1>, seq<2>>::is<1, 2>,
    unpacking<seq<0>, seq<>, seq<>>::is<0>,
    unpacking<seq<0>, seq<>, seq<2>>::is<0, 2>,
    unpacking<seq<0>, seq<1>, seq<>>::is<0, 1>,
    unpacking<seq<0>, seq<1>, seq<2>>::is<0, 1, 2>
{ };


/////////////////////////////////
// BidirectionalSequence
/////////////////////////////////
// last
template <typename ...Sn> struct last_of {
    template <int Last> struct is
    { static_assert(last_t<join<Sn...>>::value == Last, ""); };
};
struct test_last :
    last_of<seq<0>, seq<>>::is<0>,
    last_of<seq<>, seq<1>>::is<1>,
    last_of<seq<0>, seq<1>>::is<1>,

    last_of<seq<0>, seq<>, seq<>>::is<0>,
    last_of<seq<>, seq<1>, seq<>>::is<1>,
    last_of<seq<>, seq<>, seq<2>>::is<2>,
    last_of<seq<0>, seq<1>, seq<2>>::is<2>,
    last_of<seq<0>, seq<1>, seq<2, 22>>::is<22>
{ };

// init
template <typename ...Sn> struct init_of {
    template <int ...Init> struct is {
        static_assert(equal<
            vector_c<int, Init...>, init_t<join<Sn...>>
        >::value, "");
    };
};
struct test_init :
    init_of<seq<0>, seq<>>::is<>,
    init_of<seq<>, seq<1>>::is<>,
    init_of<seq<0>, seq<1>>::is<0>,

    init_of<seq<>, seq<>, seq<2>>::is<>,
    init_of<seq<>, seq<1>, seq<>>::is<>,
    init_of<seq<>, seq<1>, seq<2>>::is<1>,
    init_of<seq<0>, seq<>, seq<>>::is<>,
    init_of<seq<0>, seq<>, seq<2>>::is<0>,
    init_of<seq<0>, seq<1>, seq<>>::is<0>,
    init_of<seq<0>, seq<1>, seq<2>>::is<0, 1>,

    init_of<seq<1, 11, 111>, seq<2, 22>, seq<3, 33>>::is<1, 11, 111, 2, 22, 3>
{ };


/////////////////////////////////
// RandomAccessSequence
/////////////////////////////////
// at
template <unsigned long Index, typename ...Sn> struct at_index {
    template <int I> struct is
    { static_assert(at_c_t<join<Sn...>, Index>::value == I, ""); };
};
struct test_at :
    at_index<0, seq<1>, seq<>>::is<1>,
    at_index<0, seq<>, seq<2>>::is<2>,
    at_index<0, seq<1>, seq<2>>::is<1>,

    at_index<1, seq<1, 11>, seq<>>::is<11>,
    at_index<1, seq<1>, seq<2>>::is<2>,
    at_index<1, seq<>, seq<2, 22>>::is<22>,

    at_index<0, seq<1>, seq<2, 22>, seq<3, 33, 333>>::is<1>,
    at_index<1, seq<1>, seq<2, 22>, seq<3, 33, 333>>::is<2>,
    at_index<2, seq<1>, seq<2, 22>, seq<3, 33, 333>>::is<22>,
    at_index<3, seq<1>, seq<2, 22>, seq<3, 33, 333>>::is<3>,
    at_index<4, seq<1>, seq<2, 22>, seq<3, 33, 333>>::is<33>,
    at_index<5, seq<1>, seq<2, 22>, seq<3, 33, 333>>::is<333>
{ };

// slice
template <unsigned Start, unsigned Stop, typename ...Sn> struct slicing {
    template <int ...Slice> struct is {
        static_assert(equal<
            vector_c<int, Slice...>,
            slice_c_t<join<Sn...>, Start, Stop>
        >::value, "");
    };
};
struct test_slice :
    slicing<0, 0, seq<>, seq<>>::is<>,
    slicing<0, 0, seq<0>, seq<>>::is<>,
    slicing<0, 0, seq<>, seq<1>>::is<>,
    slicing<0, 0, seq<0>, seq<1>>::is<>,
    slicing<0, 1, seq<0>, seq<>>::is<0>,
    slicing<0, 1, seq<>, seq<1>>::is<1>,
    slicing<0, 1, seq<0>, seq<1>>::is<0>,
    slicing<1, 1, seq<0>, seq<>>::is<>,
    slicing<1, 1, seq<>, seq<1>>::is<>,
    slicing<0, 2, seq<0>, seq<1>>::is<0, 1>,

    slicing<0, 1, seq<0>, seq<1, 11, 111>, seq<2, 22>>::is<0>,
    slicing<0, 2, seq<0>, seq<1, 11, 111>, seq<2, 22>>::is<0, 1>,
    slicing<0, 3, seq<0>, seq<1, 11, 111>, seq<2, 22>>::is<0, 1, 11>,
    slicing<0, 6, seq<0>, seq<1, 11, 111>, seq<2, 22>>::is<0, 1, 11, 111, 2, 22>,
    slicing<1, 3, seq<0>, seq<1, 11, 111>, seq<2, 22>>::is<1, 11>,
    slicing<1, 4, seq<0>, seq<1, 11, 111>, seq<2, 22>>::is<1, 11, 111>,
    slicing<1, 5, seq<0>, seq<1, 11, 111>, seq<2, 22>>::is<1, 11, 111, 2>,
    slicing<1, 6, seq<0>, seq<1, 11, 111>, seq<2, 22>>::is<1, 11, 111, 2, 22>
{ };


int main() { }
