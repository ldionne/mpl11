/*!
 * @file
 * Contains unit tests for the @ref IntegralDomain typeclass.
 */

#include <boost/mpl11/integral_domain.hpp>

#include <boost/mpl11/core.hpp>

#include "test_method_dispatch.hpp"


using namespace boost::mpl11;

///////////////////////////
// Test method dispatching
///////////////////////////
namespace boost { namespace mpl11 {
    template <>
    struct IntegralDomain<Archetype<0>>
        : instantiate<IntegralDomain>::with<Archetype<0>>
    {
        template <typename, typename> using div_impl = method_tag<div>;
        template <typename, typename> using mod_impl = method_tag<mod>;
    };
}}

struct tests
    : method<div, archetype<0>, archetype<0>>
    , method<div, archetype<0>, archetype<1>>
    , method<div, archetype<1>, archetype<0>>

    , method<mod, archetype<0>, archetype<0>>
    , method<mod, archetype<0>, archetype<1>>
    , method<mod, archetype<1>, archetype<0>>
{ };


int main() { }
