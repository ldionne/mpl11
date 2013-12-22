/*!
 * @file
 * Contains unit tests for `boost::mpl11::vector`.
 */

#include <boost/mpl11/vector.hpp>

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/at.hpp>
#include <boost/mpl11/back.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/class_of.hpp>
#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/distance.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/erase.hpp>
#include <boost/mpl11/erase_range.hpp>
#include <boost/mpl11/front.hpp>
#include <boost/mpl11/has_optimization.hpp>
#include <boost/mpl11/insert.hpp>
#include <boost/mpl11/insert_range.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/join.hpp>
#include <boost/mpl11/length.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/optimization.hpp>
#include <boost/mpl11/pop_back.hpp>
#include <boost/mpl11/pop_front.hpp>
#include <boost/mpl11/prev.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/push_front.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/unpack.hpp>

#include "minimal_requirements.hpp"


using namespace boost::mpl11;
using detail::is_same;

struct x; struct y; struct z;

/////////////////////////////////
// test the vector's iterator
/////////////////////////////////
using vector_detail::iterator;

// next
static_assert(is_same<
    next<iterator<vector<x>, 0>>::type,
    iterator<vector<x>, 1>
>::value, "");

// deref
static_assert(is_same<
    deref<iterator<vector<x>, 0>>::type, x
>::value, "");

// equal
namespace test_equal {
    using V = vector<x>;
    static_assert( equal<iterator<V, 0>, iterator<V, 0>>::value, "");
    static_assert(!equal<iterator<V, 0>, iterator<V, 1>>::value, "");
    static_assert(!equal<iterator<V, 1>, iterator<V, 0>>::value, "");
    static_assert( equal<iterator<V, 1>, iterator<V, 1>>::value, "");
}

// prev
static_assert(is_same<
    prev<iterator<vector<x>, 1>>::type,
    iterator<vector<x>, 0>
>::value, "");

// advance
namespace test_advance {
    using V = vector_c<int, 0, 1>;
    static_assert(is_same<
        advance_c<iterator<V, 0>, 0>::type, iterator<V, 0>
    >::value, "");
    static_assert(is_same<
        advance_c<iterator<V, 0>, 1>::type, iterator<V, 1>
    >::value, "");
    static_assert(is_same<
        advance_c<iterator<V, 0>, 2>::type, iterator<V, 2>
    >::value, "");
    static_assert(is_same<
        advance_c<iterator<V, 1>, 1>::type, iterator<V, 2>
    >::value, "");
}

// distance
namespace test_distance {
    using V = vector_c<int, 0, 1>;
    static_assert(distance<iterator<V, 0>, iterator<V, 0>>::value == 0, "");
    static_assert(distance<iterator<V, 0>, iterator<V, 1>>::value == 1, "");
    static_assert(distance<iterator<V, 0>, iterator<V, 2>>::value == 2, "");
}

// less
namespace test_less {
    using V = vector_c<int, 0, 1>;
    static_assert(!less<iterator<V, 0>, iterator<V, 0>>::value, "");
    static_assert( less<iterator<V, 0>, iterator<V, 1>>::value, "");
    static_assert( less<iterator<V, 0>, iterator<V, 2>>::value, "");

    static_assert(!less<iterator<V, 1>, iterator<V, 0>>::value, "");
    static_assert(!less<iterator<V, 1>, iterator<V, 1>>::value, "");
    static_assert( less<iterator<V, 1>, iterator<V, 2>>::value, "");

    static_assert(!less<iterator<V, 2>, iterator<V, 0>>::value, "");
    static_assert(!less<iterator<V, 2>, iterator<V, 1>>::value, "");
    static_assert(!less<iterator<V, 2>, iterator<V, 2>>::value, "");
}

//////////////////////////////////////////////////////////////////////////////
// Vector
//////////////////////////////////////////////////////////////////////////////


/////////////////////////////////
// Sequence
/////////////////////////////////
// begin
static_assert(is_same<
    begin<vector<>>::type, iterator<vector<>, 0>
>::value, "");
static_assert(is_same<
    begin<vector<x>>::type, iterator<vector<x>, 0>
>::value, "");
static_assert(is_same<
    begin<vector<x, y>>::type, iterator<vector<x, y>, 0>
>::value, "");

// end
static_assert(is_same<
    end<vector<>>::type, iterator<vector<>, 0>
>::value, "");
static_assert(is_same<
    end<vector<x>>::type, iterator<vector<x>, 1>
>::value, "");
static_assert(is_same<
    end<vector<x, y>>::type, iterator<vector<x, y>, 2>
>::value, "");

// is_empty
static_assert( is_empty<vector<>>::value, "");
static_assert(!is_empty<vector<x>>::value, "");
static_assert(!is_empty<vector<x, y>>::value, "");
static_assert(!is_empty<vector<x, y, z>>::value, "");

// length
static_assert(length<vector<>>::value == 0, "");
static_assert(length<vector<x>>::value == 1, "");
static_assert(length<vector<x, y>>::value == 2, "");
static_assert(length<vector<x, y, z>>::value == 3, "");


/////////////////////////////////
// DirectionalSequence
/////////////////////////////////
// front
static_assert(is_same<front_t<vector<x>>, x>::value, "");
static_assert(is_same<front_t<vector<x, y>>, x>::value, "");
static_assert(is_same<front_t<vector<x, y, z>>, x>::value, "");


/////////////////////////////////
// BidirectionalSequence
/////////////////////////////////
// back
static_assert(is_same<back_t<vector<x>>, x>::value, "");
static_assert(is_same<back_t<vector<x, y>>, y>::value, "");
static_assert(is_same<back_t<vector<x, y, z>>, z>::value, "");


/////////////////////////////////
// RandomAccessSequence
/////////////////////////////////
// at
static_assert(is_same<at_c<vector<x>, 0>::type, x>::value, "");

static_assert(is_same<at_c<vector<x, y>, 0>::type, x>::value, "");
static_assert(is_same<at_c<vector<x, y>, 1>::type, y>::value, "");

static_assert(is_same<at_c<vector<x, y, z>, 0>::type, x>::value, "");
static_assert(is_same<at_c<vector<x, y, z>, 1>::type, y>::value, "");
static_assert(is_same<at_c<vector<x, y, z>, 2>::type, z>::value, "");


/////////////////////////////////
// Container
/////////////////////////////////
// new_
template <typename ...T>
using seq = test::wrapper<test::minimal_requirements<Sequence>, vector<T...>>;

template <typename V>
struct check_new {
    template <typename ...T>
    using New = apply_t<new_<V>, seq<T...>>;
    static_assert(is_same<New<>, vector<>>::value, "");
    static_assert(is_same<New<x>, vector<x>>::value, "");
    static_assert(is_same<New<x, y>, vector<x, y>>::value, "");
    static_assert(is_same<New<x, y, z>, vector<x, y, z>>::value, "");
};
struct check_all_new :
    check_new<vector<>>,
    check_new<vector<x>>,
    check_new<vector<x, y>>,
    check_new<vector<x, y, z>>
{ };

// clear
static_assert(is_same<clear<vector<>>::type, vector<>>::value, "");
static_assert(is_same<clear<vector<x>>::type, vector<>>::value, "");
static_assert(is_same<clear<vector<x, y>>::type, vector<>>::value, "");
static_assert(is_same<clear<vector<x, y, z>>::type, vector<>>::value, "");


/////////////////////////////////
// BackExtensibleContainer
/////////////////////////////////
// pop_back
static_assert(is_same<pop_back<vector<x>>::type, vector<>>::value, "");
static_assert(is_same<pop_back<vector<x, y>>::type, vector<x>>::value, "");
static_assert(is_same<pop_back<vector<x, y, z>>::type, vector<x, y>>::value, "");

// push_back
static_assert(is_same<push_back<vector<>, x>::type, vector<x>>::value, "");
static_assert(is_same<push_back<vector<x>, y>::type, vector<x, y>>::value, "");
static_assert(is_same<push_back<vector<x, y>, z>::type, vector<x, y, z>>::value, "");


/////////////////////////////////
// FrontExtensibleContainer
/////////////////////////////////
// pop_front
static_assert(is_same<pop_front_t<vector<x>>, vector<>>::value, "");
static_assert(is_same<pop_front_t<vector<x, y>>, vector<y>>::value, "");
static_assert(is_same<pop_front_t<vector<x, y, z>>, vector<y, z>>::value, "");

// push_front
static_assert(is_same<push_front_t<vector<>, x>, vector<x>>::value, "");
static_assert(is_same<push_front_t<vector<x>, y>, vector<y, x>>::value, "");
static_assert(is_same<push_front_t<vector<y, x>, z>, vector<z, y, x>>::value, "");


/////////////////////////////////
// RandomExtensibleContainer
/////////////////////////////////
template <typename V, unsigned long I>
using iter_at = typename advance_c<typename begin<V>::type, I>::type;

// insert_range
static_assert(is_same<
    insert_range_t<
        vector<>, iter_at<vector<>, 0>, vector<>
    >,
    vector<>
>::value, "");
static_assert(is_same<
    insert_range<
        vector<>, iter_at<vector<>, 0>, vector<x>
    >::type,
    vector<x>
>::value, "");
static_assert(is_same<
    insert_range<
        vector<>, iter_at<vector<>, 0>, vector<x, y>
    >::type,
    vector<x, y>
>::value, "");
static_assert(is_same<
    insert_range<
        vector<>, iter_at<vector<>, 0>, vector<x, y, z>
    >::type,
    vector<x, y, z>
>::value, "");

static_assert(is_same<
    insert_range<
        vector<x>, iter_at<vector<x>, 0>, vector<y, z>
    >::type,
    vector<y, z, x>
>::value, "");
static_assert(is_same<
    insert_range<
        vector<x, x, x>, iter_at<vector<x, x, x>, 1>, vector<y, z>
    >::type,
    vector<x, y, z, x, x>
>::value, "");

// insert
namespace test_insert {
    struct w;
    using V = vector<x, y, z>;
    static_assert(is_same<
        insert<V, iter_at<V, 0>, w>::type,
        vector<w, x, y, z>
    >::value, "");
    static_assert(is_same<
        insert<V, iter_at<V, 1>, w>::type,
        vector<x, w, y, z>
    >::value, "");
    static_assert(is_same<
        insert<V, iter_at<V, 2>, w>::type,
        vector<x, y, w, z>
    >::value, "");
    static_assert(is_same<
        insert<V, iter_at<V, 3>, w>::type,
        vector<x, y, z, w>
    >::value, "");
}

// erase_range
namespace test_erase_range {
    using V = vector<x, y, z>;
    static_assert(is_same<
        erase_range<V, iter_at<V, 0>, iter_at<V, 3>>::type,
        vector<>
    >::value, "");
    static_assert(is_same<
        erase_range<V, iter_at<V, 1>, iter_at<V, 3>>::type,
        vector<x>
    >::value, "");
    static_assert(is_same<
        erase_range<V, iter_at<V, 2>, iter_at<V, 3>>::type,
        vector<x, y>
    >::value, "");
    static_assert(is_same<
        erase_range<V, iter_at<V, 3>, iter_at<V, 3>>::type,
        vector<x, y, z>
    >::value, "");

    static_assert(is_same<
        erase_range<V, iter_at<V, 0>, iter_at<V, 2>>::type,
        vector<z>
    >::value, "");
    static_assert(is_same<
        erase_range<V, iter_at<V, 1>, iter_at<V, 2>>::type,
        vector<x, z>
    >::value, "");
    static_assert(is_same<
        erase_range<V, iter_at<V, 2>, iter_at<V, 2>>::type,
        vector<x, y, z>
    >::value, "");

    static_assert(is_same<
        erase_range<V, iter_at<V, 0>, iter_at<V, 1>>::type,
        vector<y, z>
    >::value, "");
    static_assert(is_same<
        erase_range<V, iter_at<V, 1>, iter_at<V, 1>>::type,
        vector<x, y, z>
    >::value, "");
}

// erase
namespace test_erase {
    using V = vector<x, y, z>;
    static_assert(is_same<
        erase<V, iter_at<V, 0>>::type,
        vector<y, z>
    >::value, "");
    static_assert(is_same<
        erase<V, iter_at<V, 1>>::type,
        vector<x, z>
    >::value, "");
    static_assert(is_same<
        erase<V, iter_at<V, 2>>::type,
        vector<x, y>
    >::value, "");
}


/////////////////////////////////
// Other specializations
/////////////////////////////////
// unpack
struct f { template <typename ...> struct apply { struct type; }; };
static_assert(is_same<
    unpack_t<vector<>, f>, f::apply<>::type
>::value, "");
static_assert(is_same<
    unpack_t<vector<x>, f>, f::apply<x>::type
>::value, "");
static_assert(is_same<
    unpack_t<vector<x, y>, f>, f::apply<x, y>::type
>::value, "");
static_assert(is_same<
    unpack_t<vector<x, y, z>, f>, f::apply<x, y, z>::type
>::value, "");

// join
static_assert(is_same<
    join_t<vector<>, vector<>>,
    vector<>
>::value, "");
static_assert(is_same<
    join_t<vector<>, vector<x>>,
    vector<x>
>::value, "");
static_assert(is_same<
    join_t<vector<>, vector<x, y>>,
    vector<x, y>
>::value, "");

static_assert(is_same<
    join_t<vector<x>, vector<>>,
    vector<x>
>::value, "");
static_assert(is_same<
    join_t<vector<x>, vector<y>>,
    vector<x, y>
>::value, "");
static_assert(is_same<
    join_t<vector<x>, vector<y, z>>,
    vector<x, y, z>
>::value, "");

// has_optimization
static_assert(has_optimization<vector<>, optimization::O1_length>::value, "");
static_assert(has_optimization<vector<>, optimization::O1_unpack>::value, "");


int main() { }
