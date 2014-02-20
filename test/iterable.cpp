/*!
 * @file
 * Contains unit tests for the @ref Iterable typeclass.
 */

#include <boost/mpl11/iterable.hpp>

#include "test_method_dispatch.hpp"


using namespace boost::mpl11;

namespace boost { namespace mpl11 {
    template <>
    struct Iterable<Archetype<>> {
        template <typename> using head_impl = method_tag<head>;
        template <typename> using tail_impl = method_tag<tail>;
        template <typename>
        struct is_empty_impl : method_tag<is_empty> {
            // This is required to pass the assertions in other methods
            // like head and tail.
            static constexpr bool value = false;
        };
    };
}}

struct test_method_dispatching
    : method<head, archetype<>>
    , method<tail, archetype<>>
    , method<is_empty, archetype<>>
{ };


int main() { }
