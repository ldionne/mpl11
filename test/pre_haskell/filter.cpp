/*!
 * @file
 * Contains unit tests for `boost::mpl11::filter`.
 */

#include <boost/mpl11/filter.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <int ...i>
using seq = vector_c<int, i...>;
struct pred { template <typename T> using apply = bool_<(bool)T::value>; };

/////////////////////////////////
// ForwardSequence
/////////////////////////////////
// head
template <int ...I> struct head_of {
    template <int Head> struct is
    { static_assert(head_t<filter<pred, seq<I...>>>::value == Head, ""); };
};
struct test_head :
    head_of<1>::is<1>,

    head_of<0, 2>::is<2>,
    head_of<1, 0>::is<1>,
    head_of<1, 2>::is<1>,

    head_of<1, 0, 0>::is<1>,
    head_of<0, 2, 0>::is<2>,
    head_of<0, 0, 3>::is<3>,
    head_of<1, 2, 3>::is<1>
{ };

// tail
template <int ...I> struct tail_of {
    template <int ...Tail> struct is {
        static_assert(equal<
            vector_c<int, Tail...>,
            tail_t<filter<pred, seq<I...>>>
        >::value, "");
    };
};
struct test_tail :
    tail_of<1>::is<>,

    tail_of<1, 2>::is<2>,
    tail_of<1, 0>::is<>,
    tail_of<0, 2>::is<>,

    tail_of<1, 2, 3>::is<2, 3>,
    tail_of<0, 2, 3>::is<3>,
    tail_of<1, 0, 3>::is<3>,
    tail_of<1, 2, 0>::is<2>,
    tail_of<1, 0, 0>::is<>,
    tail_of<0, 2, 0>::is<>,
    tail_of<0, 0, 3>::is<>
{ };

// is_empty
static_assert( is_empty<filter<pred, seq<>>>::value, "");

static_assert( is_empty<filter<pred, seq<0>>>::value, "");
static_assert(!is_empty<filter<pred, seq<1>>>::value, "");

static_assert(!is_empty<filter<pred, seq<1, 2>>>::value, "");
static_assert(!is_empty<filter<pred, seq<1, 0>>>::value, "");
static_assert(!is_empty<filter<pred, seq<0, 2>>>::value, "");
static_assert( is_empty<filter<pred, seq<0, 0>>>::value, "");


/////////////////////////////////
// FiniteSequence
/////////////////////////////////
// length
static_assert(length<filter<pred, seq<>>>::value == 0, "");

static_assert(length<filter<pred, seq<0>>>::value == 0, "");
static_assert(length<filter<pred, seq<1>>>::value == 1, "");

static_assert(length<filter<pred, seq<1, 2>>>::value == 2, "");
static_assert(length<filter<pred, seq<1, 0>>>::value == 1, "");
static_assert(length<filter<pred, seq<0, 2>>>::value == 1, "");
static_assert(length<filter<pred, seq<0, 0>>>::value == 0, "");

// unpack
template <int ...I> struct unpacking {
    template <int ...Filtered> struct is {
        static_assert(is_same<
            unpack_t<filter<pred, seq<I...>>, into<vector>>,
            vector_c<int, Filtered...>
        >::value, "");
    };
};
struct test_unpack :
    unpacking<>::is<>,

    unpacking<0>::is<>,
    unpacking<1>::is<1>,

    unpacking<0, 0>::is<>,
    unpacking<1, 0>::is<1>,
    unpacking<0, 2>::is<2>,
    unpacking<1, 2>::is<1, 2>,

    unpacking<1, 2, 3>::is<1, 2, 3>,
    unpacking<0, 2, 3>::is<2, 3>,
    unpacking<1, 0, 3>::is<1, 3>,
    unpacking<1, 2, 0>::is<1, 2>,
    unpacking<0, 2, 0>::is<2>
{ };


/////////////////////////////////
// BidirectionalSequence
/////////////////////////////////
// last
template <int ...I> struct last_of {
    template <int Last> struct is
    { static_assert(last_t<filter<pred, seq<I...>>>::value == Last, ""); };
};
struct test_last :
    last_of<1>::is<1>,

    last_of<0, 2>::is<2>,
    last_of<1, 0>::is<1>,
    last_of<1, 2>::is<2>,

    last_of<1, 0, 0>::is<1>,
    last_of<0, 2, 0>::is<2>,
    last_of<0, 0, 3>::is<3>,
    last_of<1, 2, 3>::is<3>
{ };

// init
template <int ...I> struct init_of {
    template <int ...Init> struct is {
        static_assert(equal<
            vector_c<int, Init...>,
            init_t<filter<pred, seq<I...>>>
        >::value, "");
    };
};
struct test_init :
    init_of<1>::is<>,

    init_of<1, 2>::is<1>,
    init_of<1, 0>::is<>,
    init_of<0, 2>::is<>,

    init_of<1, 2, 3>::is<1, 2>,
    init_of<0, 2, 3>::is<2>,
    init_of<1, 0, 3>::is<1>,
    init_of<1, 2, 0>::is<1>,
    init_of<1, 0, 0>::is<>,
    init_of<0, 2, 0>::is<>,
    init_of<0, 0, 3>::is<>
{ };


int main() { }
