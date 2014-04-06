/*!
 * @file
 * Contains unit tests for the @ref Monad typeclass.
 */

#include <boost/mpl11/monad.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/functor.hpp>

#include "test_method_dispatch.hpp"


using namespace boost::mpl11;

///////////////////////////
// Test method dispatching
///////////////////////////
namespace boost { namespace mpl11 {
    template <>
    struct Functor<Archetype<>>
        : instantiate<Functor>::with<Archetype<>>
    { };

    template <>
    struct Monad<Archetype<>> : instantiate<Monad>::with<Archetype<>> {
        template <typename> using join_impl = method_tag<join_>;
        template <typename> using unit_impl = method_tag<unit>;
    };
}}

struct tests
    : method<join_, archetype<>>
    , method<unit, Archetype<>, undefined>
{ };


int main() { }
