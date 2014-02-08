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
    struct Comparable<Archetype<0>> {
        template <typename, typename>
        using equal_impl = method_tag<equal>;

        template <typename, typename>
        using not_equal_impl = method_tag<not_equal>;
    };
}}

struct test_dispatching
    : method<equal, archetype<0>, archetype<0>>
    , method<equal, archetype<0>, archetype<1>>
    , method<equal, archetype<1>, archetype<0>>

    , method<not_equal, archetype<0>, archetype<0>>
    , method<not_equal, archetype<0>, archetype<1>>
    , method<not_equal, archetype<1>, archetype<0>>
{ };


///////////////////////////
// Test provided defaults
///////////////////////////
using Default = Comparable<default_<Integer>>;
static_assert( Default::equal_impl<int_<0>, int_<0>>::value, "");
static_assert(!Default::equal_impl<int_<0>, int_<1>>::value, "");
static_assert( Default::not_equal_impl<int_<0>, int_<1>>::value, "");
static_assert(!Default::not_equal_impl<int_<0>, int_<0>>::value, "");


int main() { }
