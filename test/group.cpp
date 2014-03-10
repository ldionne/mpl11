/*!
 * @file
 * Contains unit tests for the @ref Group typeclass.
 */

#include <boost/mpl11/group.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/integer.hpp>

#include "test_method_dispatch.hpp"


using namespace boost::mpl11;

///////////////////////////
// Test method dispatching
///////////////////////////
namespace boost { namespace mpl11 {
    template <>
    struct Group<Archetype<0>> : instantiate<Group>::with<Archetype<0>> {
        template <typename, typename> using minus_impl  = method_tag<minus>;
        template <typename>           using negate_impl = method_tag<negate>;
    };
}}

struct test_dispatching
    : method<minus, archetype<0>, archetype<0>>
    , method<minus, archetype<0>, archetype<1>>
    , method<minus, archetype<1>, archetype<0>>

    , method<negate, archetype<0>>
{ };


////////////////////////////////
// Test default implementations
////////////////////////////////
using Default = instantiate<Group>::with<Integer>;
static_assert(Default::minus_impl<int_<10>, int_<3>>::value == 10 - 3, "");
static_assert(Default::negate_impl<int_<10>>::value == -10, "");


int main() { }
