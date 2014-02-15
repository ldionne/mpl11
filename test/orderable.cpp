/*!
 * @file
 * Contains unit tests for the @ref Orderable typeclass.
 */

#include <boost/mpl11/orderable.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/integer.hpp>
#include "test_method_dispatch.hpp"


using namespace boost::mpl11;

///////////////////////////
// Test method dispatching
///////////////////////////
namespace boost { namespace mpl11 {
    template <>
    struct Orderable<Archetype<0>> {
        template <typename, typename>
        using less_impl = method_tag<less>;

        template <typename, typename>
        using less_equal_impl = method_tag<less_equal>;

        template <typename, typename>
        using greater_impl = method_tag<greater>;

        template <typename, typename>
        using greater_equal_impl = method_tag<greater_equal>;

        template <typename, typename>
        using min_impl = method_tag<min>;

        template <typename, typename>
        using max_impl = method_tag<max>;
    };
}} // end namespace boost::mpl11

template <typename x, typename y>
struct dispatch_with
    : method<less, x, y>
    , method<less_equal, x, y>
    , method<greater, x, y>
    , method<greater_equal, x, y>
    , method<min, x, y>
    , method<max, x, y>
{ };

struct test_dispatching :
    dispatch_with<archetype<0>, archetype<0>>,
    dispatch_with<archetype<0>, archetype<1>>,
    dispatch_with<archetype<1>, archetype<0>>
{ };


///////////////////////////
// Test provided defaults
///////////////////////////
struct Int;
template <int i>
struct x {
    struct type {
        static constexpr int value = i;
        using mpl_datatype = Int;
    };
};
namespace boost { namespace mpl11 {
    template <>
    struct Orderable<Int> : Orderable<default_<Int>> {
        template <typename x, typename y>
        using less_impl = bool_<(x::type::value < y::type::value)>;
    };
}}

template <int from, int to>
struct test_operators : test_operators<from, to+1> {
    static_assert(less<x<from>, x<to>>::value == from < to, "");
    static_assert(less_equal<x<from>, x<to>>::value == from <= to, "");
    static_assert(greater<x<from>, x<to>>::value == from > to, "");
    static_assert(greater_equal<x<from>, x<to>>::value == from >= to, "");
};

template <int from>
struct test_operators<from, 5> : test_operators<from+1, 0> { };

template <>
struct test_operators<5, 5> { };

static_assert(sizeof(test_operators<0, 0>), "");

// Test short-circuiting
static_assert(!less<x<1>, x<0>, undefined>::value, "");
static_assert(!less_equal<x<1>, x<0>, undefined>::value, "");
static_assert(!greater<x<0>, x<1>, undefined>::value, "");
static_assert(!greater_equal<x<0>, x<1>, undefined>::value, "");


// min
static_assert(min<x<0>, x<0>>::type::value == 0, "");
static_assert(min<x<0>, x<1>>::type::value == 0, "");
static_assert(min<x<1>, x<0>>::type::value == 0, "");
static_assert(min<x<0>, x<1>, x<2>>::type::value == 0, "");
static_assert(min<x<2>, x<1>, x<0>>::type::value == 0, "");

// max
static_assert(max<x<0>, x<0>>::type::value == 0, "");
static_assert(max<x<0>, x<1>>::type::value == 1, "");
static_assert(max<x<1>, x<0>>::type::value == 1, "");
static_assert(max<x<0>, x<1>, x<2>>::type::value == 2, "");
static_assert(max<x<2>, x<1>, x<0>>::type::value == 2, "");


int main() { }
