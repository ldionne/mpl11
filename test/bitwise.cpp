/*!
 * @file
 * Contains unit tests for the @ref Bitwise typeclass.
 */

#include <boost/mpl11/bitwise.hpp>

#include <boost/mpl11/integer.hpp>

#include "test_method_dispatch.hpp"


using namespace boost::mpl11;

///////////////////////////
// Test method dispatching
///////////////////////////
namespace boost { namespace mpl11 {
    template <>
    struct Bitwise<Archetype<0>> {
        template <typename, typename>
        using bitand_impl  = method_tag<bitand_>;

        template <typename, typename>
        using bitor_impl  = method_tag<bitor_>;

        template <typename, typename>
        using bitxor_impl  = method_tag<bitxor>;

        template <typename, typename>
        using shift_left_impl  = method_tag<shift_left>;

        template <typename, typename>
        using shift_right_impl  = method_tag<shift_right>;

        template <typename>
        using compl_impl  = method_tag<compl_>;
    };
}}

struct test_dispatching
    : method<bitand_, archetype<0>, archetype<0>>
    , method<bitand_, archetype<0>, archetype<1>>
    , method<bitand_, archetype<1>, archetype<0>>

    , method<bitor_, archetype<0>, archetype<0>>
    , method<bitor_, archetype<0>, archetype<1>>
    , method<bitor_, archetype<1>, archetype<0>>

    , method<bitxor, archetype<0>, archetype<0>>
    , method<bitxor, archetype<0>, archetype<1>>
    , method<bitxor, archetype<1>, archetype<0>>

    , method<compl_, archetype<0>>
    , method<shift_right, archetype<0>, int_<0>>
    , method<shift_left, archetype<0>, int_<0>>
{ };


int main() { }
