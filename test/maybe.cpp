/*!
 * @file
 * Contains unit tests for @ref Maybe.
 */

#include <boost/mpl11/maybe.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

template <typename x>
struct f { struct type; };

struct x { struct type; };
struct def { struct type; };

// Make sure we don't use pattern matching on boxed types.
template <typename x>
struct wrapjust : just<x> { };
struct wrapnothing : nothing { };

namespace test_maybe_metafunction {
    static_assert(std_is_same<
        maybe<def, quote<f>, wrapjust<x>>::type,
        f<x>::type
    >::value, "");

    static_assert(std_is_same<
        maybe<def, quote<f>, wrapnothing>::type,
        def::type
    >::value, "");
}

namespace test_maybe_variants {
    static_assert(is_just<wrapjust<x>>::value, "");
    static_assert(!is_just<wrapnothing>::value, "");


    static_assert(!is_nothing<wrapjust<x>>::value, "");
    static_assert(is_nothing<wrapnothing>::value, "");


    static_assert(std_is_same<
        from_just<wrapjust<x>>::type,
        x::type
    >::value, "");

    // using fails = from_just<wrapnothing>::type;


    static_assert(std_is_same<
        from_maybe<def, wrapjust<x>>::type,
        x::type
    >::value, "");

    static_assert(std_is_same<
        from_maybe<def, wrapnothing>::type,
        def::type
    >::value, "");
}

namespace test_functor_instantiation {
    static_assert(std_is_same<
        fmap<quote<f>, wrapjust<x>>::type,
        f<x>::type
    >::value, "");

    static_assert(std_is_same<
        fmap<quote<f>, wrapnothing>::type,
        nothing
    >::value, "");
}


int main() { }
