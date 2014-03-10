/*!
 * @file
 * Contains unit tests for the @ref Field typeclass.
 */

#include <boost/mpl11/field.hpp>

#include <boost/mpl11/core.hpp>

#include "test_method_dispatch.hpp"


using namespace boost::mpl11;

///////////////////////////
// Test method dispatching
///////////////////////////
namespace boost { namespace mpl11 {
    template <>
    struct Field<Archetype<0>> : instantiate<Field>::with<Archetype<0>> {
        template <typename, typename> using quot_impl  = method_tag<quot>;
        template <typename>           using recip_impl = method_tag<recip>;
    };
}}

struct tests
    : method<quot, archetype<0>, archetype<0>>
    , method<quot, archetype<0>, archetype<1>>
    , method<quot, archetype<1>, archetype<0>>

    , method<recip, archetype<0>>
{ };


int main() { }
