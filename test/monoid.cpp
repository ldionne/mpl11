/*!
 * @file
 * Contains unit tests for the @ref Monoid typeclass.
 */

#include <boost/mpl11/monoid.hpp>

#include <boost/mpl11/core.hpp>

#include "test_method_dispatch.hpp"


using namespace boost::mpl11;

///////////////////////////
// Test method dispatching
///////////////////////////
namespace boost { namespace mpl11 {
    template <>
    struct Monoid<Archetype<0>> : instantiate<Monoid>::with<Archetype<0>> {
        template <typename, typename> using plus_impl = method_tag<plus>;
        template <typename ...>       using zero_impl = method_tag<zero>;
    };
}}

struct tests
    : method<plus, archetype<0>, archetype<0>>
    , method<plus, archetype<0>, archetype<1>>
    , method<plus, archetype<1>, archetype<0>>

    , method<zero, Archetype<0>>
{ };


int main() { }
