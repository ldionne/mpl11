/*!
 * @file
 * Contains unit tests for `boost::mpl11::vector`.
 */

#include <boost/mpl11/vector.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct x; struct y; struct z;

/////////////////////////////////
// ForwardSequence
/////////////////////////////////
// head
static_assert(is_same<head_t<vector<x>>, x>::value, "");
static_assert(is_same<head_t<vector<x, y>>, x>::value, "");
static_assert(is_same<head_t<vector<x, y, z>>, x>::value, "");

// tail
static_assert(is_same<tail_t<vector<x>>, vector<>>::value, "");
static_assert(is_same<tail_t<vector<x, y>>, vector<y>>::value, "");
static_assert(is_same<tail_t<vector<x, y, z>>, vector<y, z>>::value, "");

// is_empty
static_assert( is_empty<vector<>>::value, "");
static_assert(!is_empty<vector<x>>::value, "");
static_assert(!is_empty<vector<x, y>>::value, "");
static_assert(!is_empty<vector<x, y, z>>::value, "");


/////////////////////////////////
// FiniteSequence
/////////////////////////////////
// length
static_assert(length<vector<>>::value == 0, "");
static_assert(length<vector<x>>::value == 1, "");
static_assert(length<vector<x, y>>::value == 2, "");
static_assert(length<vector<x, y, z>>::value == 3, "");

// unpack
template <int ...i>
struct test_unpack_impl {
    struct f { template <typename ...> struct apply { struct type; }; };
    template <int> struct v;

    static_assert(is_same<
        unpack_t<vector<v<i>...>, f>,
        typename f::template apply<v<i>...>::type
    >::value, "");
};
struct test_unpack :
    test_unpack_impl<>,
    test_unpack_impl<0>,
    test_unpack_impl<0, 1>,
    test_unpack_impl<0, 1, 2>,
    test_unpack_impl<0, 1, 2, 3>
{ };


/////////////////////////////////
// BidirectionalSequence
/////////////////////////////////
// last
static_assert(is_same<last_t<vector<x>>, x>::value, "");
static_assert(is_same<last_t<vector<x, y>>, y>::value, "");
static_assert(is_same<last_t<vector<x, y, z>>, z>::value, "");

// init
static_assert(is_same<init_t<vector<x>>, vector<>>::value, "");
static_assert(is_same<init_t<vector<x, y>>, vector<x>>::value, "");
static_assert(is_same<init_t<vector<x, y, z>>, vector<x, y>>::value, "");


/////////////////////////////////
// RandomAccessSequence
/////////////////////////////////
// at
template <unsigned long Index, typename ...T> struct at_index {
    template <typename X> struct is
    { static_assert(is_same<at_c_t<vector<T...>, Index>, X>::value, ""); };
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
struct slicing {
    template <typename ...Sliced> struct is {
        static_assert(is_same<
            slice_c_t<vector<T...>, Start, Stop>,
            vector<Sliced...>
        >::value, "");
    };
};
struct test_slice :
    slicing<0, 0>::is<>,

    slicing<0, 0, x>::is<>,
    slicing<0, 1, x>::is<x>,
    slicing<1, 1, x>::is<>,

    slicing<0, 0, x, y>::is<>,
    slicing<0, 1, x, y>::is<x>,
    slicing<0, 2, x, y>::is<x, y>,
    slicing<1, 1, x, y>::is<>,
    slicing<1, 2, x, y>::is<y>,
    slicing<2, 2, x, y>::is<>,

    slicing<0, 0, x, y, z>::is<>,
    slicing<0, 1, x, y, z>::is<x>,
    slicing<0, 2, x, y, z>::is<x, y>,
    slicing<0, 3, x, y, z>::is<x, y, z>,
    slicing<1, 1, x, y, z>::is<>,
    slicing<1, 2, x, y, z>::is<y>,
    slicing<1, 3, x, y, z>::is<y, z>,
    slicing<2, 2, x, y, z>::is<>,
    slicing<2, 3, x, y, z>::is<z>,
    slicing<3, 3, x, y, z>::is<>
{ };


int main() { }
