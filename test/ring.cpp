/*!
 * @file
 * Contains unit tests for the @ref Ring typeclass.
 */

#include <boost/mpl11/ring.hpp>

#include <boost/mpl11/core.hpp>

#include "test_method_dispatch.hpp"


using namespace boost::mpl11;

///////////////////////////
// Test method dispatching
///////////////////////////
namespace boost { namespace mpl11 {
    template <>
    struct Ring<Archetype<0>> : instantiate<Ring>::with<Archetype<0>> {
        template <typename, typename> using mult_impl = method_tag<mult>;
        template <typename ...>       using one_impl  = method_tag<one>;
    };
}}

struct tests
    : method<mult, archetype<0>, archetype<0>>
    , method<mult, archetype<0>, archetype<1>>
    , method<mult, archetype<1>, archetype<0>>
    , method<one, Archetype<0>>
{ };


int main() { }
