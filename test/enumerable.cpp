/*!
 * @file
 * Contains unit tests for the @ref Enumerable typeclass.
 */

#include <boost/mpl11/enumerable.hpp>

#include "test_method_dispatch.hpp"


using namespace boost::mpl11;

///////////////////////////
// Test method dispatching
///////////////////////////
namespace boost { namespace mpl11 {
    template <>
    struct Enumerable<Archetype<>> {
        template <typename> using succ_impl = method_tag<succ>;
        template <typename> using pred_impl = method_tag<pred>;
    };
}}

struct tests
    : method<succ, archetype<>>
    , method<pred, archetype<>>
{ };


int main() { }
