/*!
 * @file
 * Contains unit tests for the @ref Comparable typeclass.
 */

#include <boost/mpl11/comparable.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/integer.hpp>

#include "test_method_dispatch.hpp"


using namespace boost::mpl11;

///////////////////////////
// Test method dispatching
///////////////////////////
namespace boost { namespace mpl11 {
    template <>
    struct Comparable<Archetype<0>>
        : instantiate<Comparable>::with<Archetype<0>>
    {
        template <typename, typename>
        using equal_impl = method_tag<equal>;

        template <typename, typename>
        using not_equal_impl = method_tag<not_equal>;
    };
}}

struct test_dispatching
    : method<equal, archetype<0>, archetype<0>>
    // , method<equal, archetype<0>, archetype<1>>
    // , method<equal, archetype<1>, archetype<0>>

    , method<not_equal, archetype<0>, archetype<0>>
    // , method<not_equal, archetype<0>, archetype<1>>
    // , method<not_equal, archetype<1>, archetype<0>>
{ };


///////////////////////////
// Test provided defaults
///////////////////////////
using Default = instantiate<Comparable>::with<undefined>;
static_assert( Default::equal_impl<int_<0>, int_<0>>::value, "");
static_assert(!Default::equal_impl<int_<0>, int_<1>>::value, "");
static_assert( Default::not_equal_impl<int_<0>, int_<1>>::value, "");
static_assert(!Default::not_equal_impl<int_<0>, int_<0>>::value, "");


//////////////////////////////////////////
// Test comparison of arbitrary datatypes.
//////////////////////////////////////////
struct x;
struct y;

template <bool eq, typename ...x>
struct assert_eq {
    static_assert(eq == equal<box<x>...>::value, "");
};

template <bool eq, typename x_, typename y_>
struct assert_eq<eq, x_, y_> {
    using x = box<x_>;
    using y = box<y_>;

    static_assert(eq == equal<x, y>::value, "");
    static_assert(!equal<x, y>::value == not_equal<x, y>::value, "");
};

struct test_compare_arbitrary :
    assert_eq<true,  x, x>,
    assert_eq<false, x, y>,
    assert_eq<true,  x, x, x>,
    assert_eq<false, x, x, y>,
    assert_eq<false, x, y, undefined>,
    assert_eq<false, y, x, undefined>
{ };


int main() { }
