/*!
 * @file
 * Contains unit tests for `boost::mpl11::list`.
 */

#include <boost/mpl11/list.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/iterable_test.hpp>
#include <boost/mpl11/quote.hpp>


using namespace boost::mpl11;
using detail::is_same;

struct x { struct type; };
struct y { struct type; };
struct z { struct type; };

template <typename ...T>
struct list_of
    : detail::iterable_test<list<T...>, T...>
{ };

struct tests :
    list_of<>,
    list_of<x>,
    list_of<x, y>,
    list_of<x, y, z>,
    list_of<x, y, z, x, y, z>
{ };

// We also need to perform manual tests here because `iterable_test` uses
// `list` in its implementation.

// head
static_assert(is_same<head_t<list<x>>, x::type>::value, "");
static_assert(is_same<head_t<list<x, y>>, x::type>::value, "");
static_assert(is_same<head_t<list<x, y, z>>, x::type>::value, "");

// tail
static_assert(is_same<tail_t<list<x>>, list<>::type>::value, "");
static_assert(is_same<tail_t<list<x, y>>, list<y>::type>::value, "");
static_assert(is_same<tail_t<list<x, y, z>>, list<y, z>::type>::value, "");

// is_empty
static_assert( is_empty<list<>>::value, "");
static_assert(!is_empty<list<x>>::value, "");
static_assert(!is_empty<list<x, y>>::value, "");
static_assert(!is_empty<list<x, y, z>>::value, "");

// length
static_assert(length<list<>>::value == 0, "");
static_assert(length<list<x>>::value == 1, "");
static_assert(length<list<x, y>>::value == 2, "");
static_assert(length<list<x, y, z>>::value == 3, "");

// unpack
template <int ...i>
struct test_unpack_impl {
    template <typename ...> struct f_ { struct type; }; using f = quote<f_>;
    template <int> struct v;

    static_assert(is_same<
        unpack_t<list<v<i>...>, f>,
        apply_t<f, v<i>...>
    >::value, "");
};
struct test_unpack :
    test_unpack_impl<>,
    test_unpack_impl<0>,
    test_unpack_impl<0, 1>,
    test_unpack_impl<0, 1, 2>,
    test_unpack_impl<0, 1, 2, 3>
{ };

// last
static_assert(is_same<last_t<list<x>>, x::type>::value, "");
static_assert(is_same<last_t<list<x, y>>, y::type>::value, "");
static_assert(is_same<last_t<list<x, y, z>>, z::type>::value, "");

// at
template <unsigned long Index, typename ...T> struct at_index {
    template <typename X> struct is {
        static_assert(is_same<
            at_c_t<list<T...>, Index>,
            typename X::type
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


int main() { }
