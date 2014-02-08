/*!
 * @file
 * Contains unit tests for the @ref Functor typeclass.
 */

#include <boost/mpl11/functor.hpp>

#include <boost/mpl11/core.hpp>
#include "test_method_dispatch.hpp"


using namespace boost::mpl11;

///////////////////////////
// Test method dispatching
///////////////////////////
namespace boost { namespace mpl11 {
    template <>
    struct Functor<Archetype<>> {
        template <typename, typename> using fmap_impl = method_tag<fmap>;
    };
}}

struct tests : method<fmap, undefined, archetype<>> { };


int main() { }
