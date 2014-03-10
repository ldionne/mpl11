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

struct x;
struct def { struct type; };

namespace test_maybe_metafunction {
    static_assert(std_is_same<
        maybe<def, quote<f>, just<x>>::type,
        f<x>::type
    >::value, "");

    static_assert(std_is_same<
        maybe<def, quote<f>, nothing>::type,
        def::type
    >::value, "");
}

namespace test_functor_instantiation {
    static_assert(std_is_same<
        fmap<quote<f>, just<x>>::type,
        f<x>::type
    >::value, "");

    static_assert(std_is_same<
        fmap<quote<f>, nothing>::type,
        nothing
    >::value, "");
}


int main() { }
