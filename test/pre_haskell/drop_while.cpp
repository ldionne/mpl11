/*!
 * @file
 * Contains unit tests for `boost::mpl11::drop_while`.
 */

#include <boost/mpl11/drop_while.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <int ...i>
using seq = vector_c<int, i...>;
struct pred { template <typename T> using apply = bool_<!T::value>; };
template <int ...i> using drop_0s = drop_while<pred, seq<i...>>;

/////////////////////////////////
// ForwardSequence
/////////////////////////////////
// head
template <int ...I> struct head_of {
    template <int Head> struct is
    { static_assert(head_t<drop_0s<I...>>::value == Head, ""); };
};
struct test_head :
    head_of<1>::is<1>,

    head_of<0, 1>::is<1>,
    head_of<1, 0>::is<1>,

    head_of<0, 1, 2>::is<1>,
    head_of<1, 0, 2>::is<1>,
    head_of<1, 2, 0>::is<1>,
    head_of<0, 0, 1>::is<1>,
    head_of<0, 1, 0>::is<1>
{ };

// tail
template <int ...I> struct tail_of {
    template <int ...Tail> struct is {
        static_assert(equal<
            vector_c<int, Tail...>, tail_t<drop_0s<I...>>
        >::value, "");
    };
};
struct test_tail :
    tail_of<1>::is<>,

    tail_of<0, 1>::is<>,
    tail_of<1, 0>::is<0>,
    tail_of<1, 2>::is<2>,

    tail_of<1, 2, 3>::is<2, 3>,
    tail_of<0, 2, 3>::is<3>,
    tail_of<0, 0, 3>::is<>,
    tail_of<1, 0, 3>::is<0, 3>,
    tail_of<1, 2, 0>::is<2, 0>,
    tail_of<1, 0, 0>::is<0, 0>
{ };

// is_empty
static_assert( is_empty<drop_0s<>>::value, "");

static_assert( is_empty<drop_0s<0>>::value, "");
static_assert(!is_empty<drop_0s<1>>::value, "");

static_assert( is_empty<drop_0s<0, 0>>::value, "");
static_assert(!is_empty<drop_0s<1, 0>>::value, "");
static_assert(!is_empty<drop_0s<0, 2>>::value, "");
static_assert(!is_empty<drop_0s<1, 2>>::value, "");


/////////////////////////////////
// FiniteSequence
/////////////////////////////////
// length
static_assert(length<drop_0s<>>::value == 0, "");

static_assert(length<drop_0s<0>>::value == 0, "");
static_assert(length<drop_0s<1>>::value == 1, "");

static_assert(length<drop_0s<0, 0>>::value == 0, "");
static_assert(length<drop_0s<1, 0>>::value == 2, "");
static_assert(length<drop_0s<0, 2>>::value == 1, "");
static_assert(length<drop_0s<1, 2>>::value == 2, "");

// unpack
template <int ...I> struct unpacking {
    template <int ...Filtered> struct is {
        static_assert(is_same<
            unpack_t<drop_0s<I...>, into<vector>>,
            vector_c<int, Filtered...>
        >::value, "");
    };
};
struct test_unpack :
    unpacking<>::is<>,

    unpacking<0>::is<>,
    unpacking<1>::is<1>,

    unpacking<0, 0>::is<>,
    unpacking<0, 2>::is<2>,
    unpacking<1, 0>::is<1, 0>,
    unpacking<1, 2>::is<1, 2>,

    unpacking<0, 0, 0>::is<>,
    unpacking<0, 2, 3>::is<2, 3>,
    unpacking<1, 0, 3>::is<1, 0, 3>,
    unpacking<1, 2, 0>::is<1, 2, 0>,
    unpacking<1, 0, 0>::is<1, 0, 0>,
    unpacking<0, 2, 0>::is<2, 0>,
    unpacking<0, 0, 3>::is<3>,
    unpacking<1, 2, 3>::is<1, 2, 3>
{ };


int main() { }
